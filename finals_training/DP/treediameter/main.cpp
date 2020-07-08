#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<bool> visited;
priority_queue<pair<int, int>> q;
vector<int>p;
void dfs(int cur, int parent, int d, vector<vector<int>> &E) {
    for (int next : E[cur]) {
        if (next == 0 || next == parent) { continue; }

        p[next]=cur;
        if (E[next].size() == 1) { q.push(make_pair(d + 1, next)); }
        dfs(next, cur, d + 1, E);
    }
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    visited = vector<bool>(n, false);
    visited[0] = true;
    p=vector<int>(n, -1);
    dfs(0, -1, 0, E);
    vector<int> depthUnderNode(n, 0);
    int maxPath = 0;

    while (q.size()) {
        int cur = q.top().second;
        int curDepth = q.top().first;


        q.pop();

        int next = p[cur];
        maxPath=max(maxPath, depthUnderNode[next] + depthUnderNode[cur] + 1);

        depthUnderNode[next]=max(depthUnderNode[cur] + 1, depthUnderNode[next]);

        if (visited[next]) { continue; }
        visited[next] = true;
        q.push(make_pair(curDepth - 1, next));
    }

    cout << maxPath;
}