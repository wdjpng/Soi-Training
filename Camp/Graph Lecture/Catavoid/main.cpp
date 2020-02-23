#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e12;
deque<int> path;

bool reconstructPath(vector<vector<int>> const &E, int cur, int end, vector<bool> visited) {
    path.push_back(cur);
    if (cur == end) {
        return true;
    }
    for (int next : E[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            bool shouldBreak = reconstructPath(E, next, end, visited);

            if (shouldBreak) {
                return shouldBreak;
            }
        }
    }
    path.pop_back();
    return false;
}

void dfs(int cur, vector<vector<int>> &E, vector<int> &depth, vector<int> &consecutiveProtection, vector<int>&parent) {
    for (int next : E[cur]) {
        if (depth[next] == MAX) {
            parent[next] = cur;
            depth[next] = depth[cur] + 1;
            dfs(next, E, depth, consecutiveProtection, parent);
        } else if (next != parent[cur]) {
            consecutiveProtection[next]++;
            consecutiveProtection[parent[cur]]--;
        }
    }
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> depth(n, MAX);
    vector<int> consecutiveProtection(n);

    vector<vector<int>> E(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }

    vector<int> parent(E.size(), -1);
    depth[a]=0;
    parent[a]=-1;
    dfs(a, E, depth, consecutiveProtection, parent);
    vector<bool> visited(n, false);
    visited[a] = true;
    reconstructPath(E, a, b, visited);



    int curProtection = 0;
    int catCounter = 0;

    while (path.size()) {
        int cur = path.front();
        path.pop_front();
        if (cur == b) {
            cout << catCounter+1 << "\n";
            exit(0);
        }
        if (curProtection == 0) { catCounter++; };
        curProtection += consecutiveProtection[cur];
    }
}