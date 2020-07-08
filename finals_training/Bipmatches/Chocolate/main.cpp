#include <bits/stdc++.h>

#define int long long
using namespace std;

int n = 0, m = 0;
vector<vector<int>> E;
vector<int> matching;

vector<bool> visited;
vector<bool> isBlocked;

bool improveMatching(int i) {
    if (visited[i] || isBlocked[i]) { return false; }

    visited[i] = true;
    if (i < n) {
        if (matching[i] == -1) { return true; }

        return improveMatching(matching[i]);
    } else {
        for (int next : E[i]) {
            if (matching[next] == i) { continue; }

            if (improveMatching(next)) {
                matching[next] = i;
                return true;
            }
        }
    }

    return false;
}

vector<int> covered;

void updateCovered() {
    covered.assign(m, -1);

    for (int i = 0; i < matching.size(); ++i) {
        if (matching[i] != -1) {
            covered[matching[i] - n] = i;
        }
    }
    for (int i = n; i < n + m; ++i) {
        if (isBlocked[i]) { covered[i] = n + m; }
    }
}


bool improveMatching() {
    updateCovered();

    visited.assign(n + m, false);
    for (int i = n; i < n + m; ++i) {
        if (covered[i - n] == -1 && improveMatching(i)) {
            return true;
        }
    }

    return false;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int r, c, k;
    cin >> c >> r >> k;

    if (r * c % 2) {
        cout << "-1";
        exit(1);
    }
    vector<vector<int>> val(r, vector<int>(c, -1));
    bool flag1 = false;
    for (int i = 0; i < r; ++i) {
        bool flag2 = flag1;
        flag1 = !flag1;
        for (int j = 0; j < c; ++j) {
            flag2 = !flag2;
            if (flag2) {
                val[i][j] = n;
                n++;
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (val[i][j] == -1) {
                val[i][j] = n + m;
                m++;
            }
        }
    }

    E = vector<vector<int>>(r * c);
    isBlocked.assign(n + m, false);
    matching.assign(n, -1);
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= y + 1; ++y) {
                    if (y == r || x == c) break;
                    if (abs(x - i) + abs(y - j) > 1) { continue; }
                    if (y < 0 || x < 0 || (i == x && j == y)) { continue; }

                    E[val[j][i]].push_back(val[y][x]);
                }
            }
        }
    }


    int offsetI = 0, offsetJ = 0;
    if (r % 2 || c % 2) {
        if (r % 2) { offsetJ = 1; }
        else {
            offsetI = 1;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; ++j) {
            if ((c % 2 && i % 2) || (r % 2 && j % 2)) { continue; }
            matching[min(val[i + offsetI][j + offsetJ], val[i][j])] = max(val[i + offsetI][j + offsetJ], val[i][j]);
        }
    }
    updateCovered();
    bool finished = false;
    for (int i = 0; i < k; ++i) {
        int b;
        cin >> b;

        for (int j = 0; j < b; ++j) {
            int x, y;
            cin >> x >> y;

            int value = val[y - 1][x - 1];
            isBlocked[value] = true;
            if (value >= n) { value = covered[value - n]; }
            covered[matching[value] - n] = -1;
            matching[value] = -1;
        }

        while (improveMatching()) {}
        for (int f = 0; f < n + m; f++) {
            if (isBlocked[f] || (f >= n && covered[f - n] != -1) || (f < n && matching[f] != -1)) { continue; }
            cout << -1;
            finished = true;
            break;
        }
        if (finished) { break; }
    }
}