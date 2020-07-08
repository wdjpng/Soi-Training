#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define int long long
using namespace std;

int dfs(vector<bool>& visited, vector<vector<int>>& adjencyList, int& cur){
    int counter = 1;
    for (int i = 0; i < adjencyList[cur].size(); ++i) {
        if(!visited[adjencyList[cur][i]]){
            visited[adjencyList[cur][i]] = true;
            counter += dfs(visited, adjencyList, adjencyList[cur][i]);
        }
    }

    return counter;
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

    int counter = 0;
    vector<bool> visited(n, false);
    for (int j = 0; j < n; ++j) {
        if(!visited[j]){
            visited[j] = true;
            int cur = dfs(visited, adjencyList, j);
            if(cur % 2 == 1){
                counter+=cur;
            }
        }
    }

    cout <<  counter <<"\n";
}