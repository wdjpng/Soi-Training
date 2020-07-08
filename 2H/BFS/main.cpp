#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define int long long

using namespace std;


signed main() {
    int n, m;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<vector<int>> E(n);
    vector<int> depth(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    queue<int> toVisit;
    toVisit.push(0);
    depth[0] = 0;
    while (toVisit.size()) {
        int cur = toVisit.front();
        toVisit.pop();

        for (int i = 0; i < E[cur].size(); ++i) {
            int nextNode = E[cur][i];
            if (depth[nextNode] == -1) {
                toVisit.push(nextNode);
                depth[nextNode] = depth[cur] + 1;
            }
        }
    }



    //Printing the result
    cout << depth[n - 1] << "\n";
}