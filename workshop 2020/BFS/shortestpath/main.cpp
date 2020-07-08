#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjacencyList(n);
    vector<int> depth(n, -1);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }

    int start, end;
    cin >> start >> end;


    queue<int> nodesToDo;
    nodesToDo.push({start});
    depth[start] = 0;
    while (nodesToDo.size()){
        int cur = nodesToDo.front();
        nodesToDo.pop();

        for (int i = 0; i < adjacencyList[cur].size(); ++i) {
            if(depth[adjacencyList[cur][i]] == -1){
                depth[adjacencyList[cur][i]] = depth[cur]+1;
                nodesToDo.push(adjacencyList[cur][i]);
            }
        }
    }

    cout << depth[end] << "\n";

}