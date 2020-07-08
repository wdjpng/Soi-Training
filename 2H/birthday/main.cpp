#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define int long long

using namespace std;

void bfs(int start, string& output, vector<vector<int>>& E, vector<bool>& visited, vector<bool>& isInCurrentSearch){
    visited[start] = true;
    isInCurrentSearch[start] = true;

    for (int i = 0; i < E[start].size(); ++i) {
        int nextNode = E[start][i];

        if(isInCurrentSearch[nextNode]){
            cout << "IMPOSSIBLE\n";
            exit(0);
        }

        if(!visited[nextNode]){
            output+= to_string(nextNode) + ' ';
            bfs(nextNode, output, E, visited, isInCurrentSearch);
        }
    }

    isInCurrentSearch[start] = false;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> E(n);

    vector<bool> visited(n, false);
    vector<bool> isInCurrentSearch(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }

    string output = "";
    for (int start = 0; start < n; ++start) {
       if(!visited[start]){
            if(!visited[start]){
                output+=to_string(start) + ' ';
                bfs(start, output, E, visited, isInCurrentSearch);
            }
       }
    }

    cout << "POSSIBLE\n" << output << "\n";
}