#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long
using namespace std;

void bfs(vector<vector<int>>& adjencyList, vector<int>& coloring, int cur){
    queue<int> nodesToVisit;
    coloring[cur] = 0;
    nodesToVisit.push(cur);

    while (nodesToVisit.size()){
        cur = nodesToVisit.front();
        nodesToVisit.pop();

        for (int i = 0; i < adjencyList[cur].size(); ++i) {
            if(coloring[adjencyList[cur][i]] == -1){
                coloring[adjencyList[cur][i]] = !coloring[cur];
                nodesToVisit.push(adjencyList[cur][i]);
            } else if(coloring[adjencyList[cur][i]] == coloring[cur]){
               cout << "Order more passports.\n";
               exit(0);
            }
        }
    }


}
signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjencyList(n);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adjencyList[start].push_back(end);
        adjencyList[end].push_back(start);
    }

    vector<int> coloring(n, -1);

    for (int i = 0; i < n; ++i) {
        if(coloring[i] == -1){
            bfs(adjencyList, coloring, i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if(!coloring[i]){
            cout << i << " ";
        }
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        if(coloring[i]){
            cout << i << " ";
        }
    }
    cout << "\n";

}