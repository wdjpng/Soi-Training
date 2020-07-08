#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<vector<bool>>vis;
int n, m, k;
int dfs(int x, int y){
    if(vis[x][y]){return 0;}
    vis[x][y]=true;
    int sum = 1;
    for (int x1 = x-1; x1 <= x+1; ++x1) {
        for (int y1 = y-1; y1 <= y+1; ++y1) {
            if(x1<0||y1<0||x1>=n||y1>=m||vis[x1][y1]||abs(x1-x)+abs(y1-y)>1){ continue;}
            sum+=dfs(x1, y1);
        }
    }

    return sum;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n >> m >> k;
    vis.assign(n, vector<bool>(m));

    for (int i = 0; i < k; ++i) {
        int x,y;
        cin >> x >> y;
        vis[x][y]=true;
    }

    int sum = 0;
    for (int x = 0; x < n; ++x) {
        sum+=dfs(x,0)  + dfs(x,m-1);
    }

    for (int y = 0; y < m; ++y) {
        sum+=dfs(0,y)+dfs(n-1,y);
    }

    cout << n*m-k-sum;
}