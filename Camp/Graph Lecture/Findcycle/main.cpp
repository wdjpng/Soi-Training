#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

vector<int>parents;
vector<bool>visited;
vector<vector<int>>E;
int counter = 0;

void dfs(int v, int p){
    visited[v] = true;
    parents[v] = p;
    for(int w : E[v]){
        if(w == p) continue;
        if(visited[w]){
            vector<int>output(1, v);
            while (output.back() != w){
                output.push_back(parents[output.back()]);
            }

            cout << output.size() << "\n";
            for (int i = 0; i < output.size(); ++i) {
                cout << output[i] << " ";
            }
            exit(0);
        } else{
            dfs(w, v);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    parents = vector<int>(n);
    visited = vector<bool>(n, false);
    E = vector<vector<int>>(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if(!visited[i]){
            dfs(i, -1);
        }
    }
    cout << "NO\n";
}