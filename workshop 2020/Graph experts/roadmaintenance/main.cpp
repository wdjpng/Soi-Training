#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define int long long
using namespace std;


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

    vector<pair<int, int>> connections;
    vector<bool> visited(n, false);


    stack<pair<int, int>> myStack;
    myStack.push({0, -1});

    while (myStack.size()){
        int cur = myStack.top().first;
        int origin = myStack.top().second;
        myStack.pop();
        visited[cur] = true;
        for (int i = 0; i < adjencyList[cur].size(); ++i) {
            if(!visited[adjencyList[cur][i]]){
               myStack.push({adjencyList[cur][i], cur});
                visited[adjencyList[cur][i]] = true;
            } else if(adjencyList[cur][i] != origin){
                connections.push_back({max(cur, adjencyList[cur][i]), min(cur, adjencyList[cur][i])});
            }
        }
    }

    cout << connections.size()/2 << "\n";
    sort(connections.begin(), connections.end());
    for (int j = 0; j < connections.size(); j+=2) {
        cout << connections[j].first << " " << connections[j].second << "\n";
    }


}