#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

vector<int> parents;
vector<bool> visited;
vector<vector<int>> E;
vector<int> index;
int counter = 0;
vector<pair<int, int>> bridges;
vector<bool> isCut;

int dfs(int v, int p) {
    index[v] = ++counter;
    visited[v] = true;
    parents[v] = p;
    int children = 0;
    int lowlink = index[v];

    for (int w : E[v]) {
        if (w == p) continue;
        if (visited[w]) {
            lowlink = min(lowlink, index[w]);
        } else {
            ++children;
            int nextLowLink = dfs(w, v);
            lowlink = min(lowlink, nextLowLink);

            if (nextLowLink > index[v]) {
                bridges.push_back(make_pair(min(v, w), max(v, w)));
            }

            if (nextLowLink >= index[v] && parents[v] != -1) {
                isCut[v] = true;
            }
        }
    }

    if (parents[v] == -1 && children > 1){
        isCut[v] = true;
    }

    return  lowlink;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    parents = vector<int>(n);
    visited = vector<bool>(n, false);
    E = vector<vector<int>>(n);
    index = vector<int>(n);
    isCut = vector<bool>(n, false);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs(0, -1);
    if (t == 0){
        for (int i = 0; i < n; ++i) {
            cout << isCut[i] << " ";
        }
    } else{
        sort(bridges.begin(), bridges.end());
        cout << bridges.size() << "\n";
        for (int i = 0; i < bridges.size(); ++i) {
            cout << bridges[i].first << " " << bridges[i].second << "\n";
        }
    }
}