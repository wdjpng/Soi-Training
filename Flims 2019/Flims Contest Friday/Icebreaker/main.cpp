#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, groups;
    cin >> n >> groups;
    vector<vector<bool>>con(n, vector<bool>(n));
    vector<vector<int>>E(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            con[i][x]=true;
            con[x][i]=true;
            E[x].push_back(i);
        }
    }
    vector<int>first, second;
    vector<int>cols(n,-1);
    vector<vector<int>>g(groups);
    for (int i = 0; i < n; ++i) {
        vector<bool>used(groups);
        for (int w : E[i]) {
            if(cols[w]==-1){ continue;}
            used[cols[w]]=true;
        }
        for (int j = 0; j < groups; ++j) {
            if(used[j]){ continue;}
            cols[i]=j;
            g[j].push_back(i);
            break;
        }
    }

    for (int i = 0; i < groups; ++i) {
        cout << g[i].size() << " ";
        for (int j = 0; j < g[i].size(); ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}