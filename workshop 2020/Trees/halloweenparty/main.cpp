#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>>E(n);
    vector<vector<int>>E_reversed(n);
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;

        E[a].push_back(i);
        E_reversed[i].push_back(a);
    }

    queue<int> queue;
    vector<int>depth(n, -1);

    int maxDepth = 1;
    depth[0] = 1;
    queue.push(0);

    while (queue.size()){
        int cur = queue.front();
        queue.pop();

        for (int i = 0; i < E[cur].size(); ++i) {
            depth[E[cur][i]] = depth[cur] + 1;
            queue.push(E[cur][i]);

            maxDepth = max(maxDepth, depth[cur] + 1);
        }
    }

    cout << maxDepth << "\n";
}