#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

vector<bool> visited;
vector<vector<int>> E;

int dfs(int v) {
    visited[v]=true;
    bool haveToReturnZero = false;
    int counter = 0;
    stack<int>stack;
    stack.push(v);

    while (stack.size()){
        int cur = stack.top();
        if(E[cur].size() == 1){
            haveToReturnZero = true;
        }

        stack.pop();
        counter++;

        for(int next : E[cur]){
            if(!visited[next]){
                stack.push(next);
                visited[next] = true;
            }
        }
    }

    if(haveToReturnZero){
        return 0;
    }

    return counter;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    visited = vector<bool>(n, false);
    E = vector<vector<int>>(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if(!visited[i]){
            counter += dfs(i);
        }
    }

    cout << counter << "\n";
}