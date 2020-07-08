#include <bits/stdc++.h>

#define int long long
using namespace std;

const int INF = 1e16;

// Finally found that edge case
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
     ios_base::sync_with_stdio(false);
     // Disable automatic flush of cout when reading from cin cin.tie(0);
     cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<pair<int, int>>> E(n);
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        E[b].push_back(make_pair(a, d));
    }

    vector<int> depth(n, -INF);
    if (!t) {
        depth = vector<int>(n, INF);
    }

    depth[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (pair<int, int> next : E[i]) {
            if (t) {
                depth[i] = max(depth[next.first] + next.second, depth[i]);
            } else {
                depth[i] = min(depth[next.first] + next.second, depth[i]);
            }
        }
    }

    if (depth[n - 1] >= INF/10 || depth[n - 1] <= -INF/10) {
        cout << "Impossible";
    } else {
        cout << depth[n - 1];
    }
}