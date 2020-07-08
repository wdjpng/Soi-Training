#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define int long long
using namespace std;

int dfs(vector<bool>& visited, vector<vector<int>>& adjencyList, int& cur, vector<int>& prices){
    int sum = 0;
    for (int i = 0; i < adjencyList[cur].size(); ++i) {
        if(!visited[adjencyList[cur][i]]){
            visited[adjencyList[cur][i]] = true;
            sum += prices[adjencyList[cur][i]] + dfs(visited, adjencyList, adjencyList[cur][i], prices);
        }
    }

    return sum;
}
signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> prices(n);
    vector<vector<int>> adjencyList(n);

    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adjencyList[start].push_back(end);
        adjencyList[end].push_back(start);
    }

    int maximum = -1;
    vector<bool> visited(n, false);
    for (int j = 0; j < n; ++j) {
        if(!visited[j]){
            visited[j] = true;
            int cur = prices[j] + dfs(visited, adjencyList, j, prices), max;
            if(cur > maximum){
                maximum = cur;
            }
        }
    }

    cout <<  maximum <<"\n";
}