#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define int long long
using namespace std;

//This is currently not working

void dfs(vector<bool>& visited, vector<vector<int>>& adjencyList, vector<int>& currentBadges, vector<int>& requiredBadges, vector<int>& aquiredBadges, vector<bool>& canReach, int cur){
    for (int i = 0; i < adjencyList[cur].size(); ++i) {
        if(!visited[adjencyList[cur][i]]){
            visited[adjencyList[cur][i]] = true;
            if(currentBadges[requiredBadges[adjencyList[cur][i]]]){
                currentBadges[aquiredBadges[adjencyList[cur][i]]]++;
                dfs(visited, adjencyList, currentBadges, requiredBadges, aquiredBadges, canReach, adjencyList[cur][i]);
            } else{
                canReach[adjencyList[cur][i]] = false;
            }
        }
    }

    currentBadges[aquiredBadges[cur]]--;
}
signed main() {
    int n;
    cin >> n;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjencyList(n);

    vector<int> aquiredBadges(n);
    vector<int> requiredBadges(n);
    for (int i = 0; i < n; ++i) {
        cin >> aquiredBadges[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> requiredBadges[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int start, end;
        cin >> start >> end;

        adjencyList[start].push_back(end);
        adjencyList[end].push_back(start);
    }

    vector<int> parent(n);
    stack<int> myStack;
    myStack.push(0);

    vector<bool>visited(n, false);
    while (myStack.size()){
        int cur = myStack.top();
        myStack.pop();
        visited[cur] = true;
        for (int i = 0; i < adjencyList[cur].size(); ++i) {
           if(!visited[adjencyList[cur][i]]){
               parent[adjencyList[cur][i]] = cur;
               myStack.push(adjencyList[cur][i]);
               visited[adjencyList[cur][i]] = true;
           }
        }
    }

    vector<int> currentBadges(n, 0);
    myStack.push(0);
    vector<bool> canReach(n, true);
    currentBadges[aquiredBadges[0]] = 1;

    visited = vector<bool>(n, false);
    visited[0] = true;
    dfs(visited, adjencyList, currentBadges, requiredBadges, aquiredBadges, canReach, 0);
    for (int j = 0; j < n; j++) {
        if(canReach[j]){
            cout << "1 ";
        } else{
            cout << "0 ";
        }
    }

    cout << "\n";
}
