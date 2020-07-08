#include <bits/stdc++.h>

#define int long long

using namespace std;

//I would like to have back my sanity
vector<string> maze;
vector<vector<pair<bool, bool>>> visited;

int isLeft(pair<float, float> pos) {
    bool result;
    if (pos.first < 0 || pos.second < 0 || pos.first >= maze.size() || pos.second >= maze[0].size()) {
        return -1;
    }


    char character = maze[floor(pos.first)][floor(pos.second)];
    double x = pos.second - floor(pos.second);
    double y = pos.first - floor(pos.first);
    if (character == '/') {
        result = y < -x + 1;
    } else {
        result = y > x;
    }

    if (result && visited[floor(pos.first)][floor(pos.second)].first) {
        return -1;
    } else if (!result && visited[floor(pos.first)][floor(pos.second)].second) {
        return -1;
    }

    return result;
}

struct dist {
    int walls = -1, walked = -1, r = -1, c = -1, isLeft;
};

bool operator<(const dist &a, const dist &b) {
    return make_pair(a.walls, a.walked) > make_pair(b.walls, b.walked);
}

void pushWithCheck(dist d, priority_queue<dist> &pq) {
    if (d.isLeft != -1) {
        pq.push(d);
        if (d.isLeft) {
            visited[d.r][d.c].first = true;
        } else {
            visited[d.r][d.c].second = true;
        }
    }
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int r, c, w;
    cin >> r >> c >> w;
    maze = vector<string>(r);
    for (int i = 0; i < r; ++i) {
        cin >> maze[i];
    }

    float a_r, a_c, b_r, b_c;
    cin >> a_r >> a_c >> b_r >> b_c;

    visited = vector<vector<pair<bool, bool>>>(r, vector<pair<bool, bool>>(c, make_pair(false, false)));
    priority_queue<dist> pq;
    if (isLeft(make_pair(a_r, a_c))) {
        visited[floor(a_r)][floor(a_c)].first = true;
        pq.push(dist({0, 0, (int) floor(a_r), (int) floor(a_c), true}));
    } else {
        visited[floor(a_r)][floor(a_c)].second = true;
        pq.push(dist({0, 0, (int) floor(a_r), (int) floor(a_c), false}));
    }

    dist searchedDistance = dist({-1, -1, (int) floor(b_r), (int) floor(b_c), isLeft(make_pair(b_r, b_c))});
    while ((pq.top().isLeft != searchedDistance.isLeft&&searchedDistance.isLeft!=-1) || pq.top().c != searchedDistance.c ||
           pq.top().r != searchedDistance.r) {
        dist cur = pq.top();
        pq.pop();

        dist up = dist({cur.walls, cur.walked + 1, cur.r - 1, cur.c, isLeft(make_pair(cur.r - 0.02, cur.c + 0.5))});
        dist down = dist({cur.walls, cur.walked + 1, cur.r + 1, cur.c, isLeft(make_pair(cur.r + 1.02, cur.c + 0.5))});
        dist left = dist({cur.walls, cur.walked + 1, cur.r, cur.c - 1, isLeft(make_pair(cur.r + 0.5, cur.c - 0.02))});
        dist right = dist({cur.walls, cur.walked + 1, cur.r, cur.c + 1, isLeft(make_pair(cur.r + 0.5, cur.c + 1.01))});

        dist switchSide = dist({cur.walls + 1, cur.walked + 1, cur.r, cur.c, !cur.isLeft});

        if (cur.isLeft) {
            if (visited[cur.r][cur.c].second) {
                switchSide.isLeft = -1;
            }
            pushWithCheck(left, pq);
            if (maze[cur.r][cur.c] == '/') {
                pushWithCheck(up, pq);
            } else {
                pushWithCheck(down, pq);
            }
        } else {
            if (visited[cur.r][cur.c].first) {
                switchSide.isLeft = -1;
            }
            pushWithCheck(right, pq);
            if (maze[cur.r][cur.c] == '/') {
                pushWithCheck(down, pq);
            } else {
                pushWithCheck(up, pq);
            }
        }


        pushWithCheck(switchSide, pq);
    }

    cout << pq.top().walls;
    if (w) {
        cout << " " << pq.top().walked;
    }
    cout << "\n";
}