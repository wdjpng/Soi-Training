#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>>mp(n, vector<int>(m));
    pair<int,int>top=make_pair(0,0);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        for (int j = 0; j < m; ++j) {
            mp[i][j]=a[j]=='.';
            if(a[j]=='.'){
                top=make_pair(i, j);
                s++;
            }
        }
    }

    queue<pair<int, int>>q;
    q.push(top);
    vector<vector<bool>>visited(n, vector<bool>(m));
    visited[top.first][top.second]=true;

    int curN=0;
    while (q.size()){
        auto c=q.front();
        q.pop();

        if(curN==s-k){ break;}
        curN++;
        mp[c.first][c.second]=2;

        for (int i = c.first-1; i <= c.first+1; ++i) {
            for (int j = c.second-1; j <= c.second+1; ++j) {
                if(abs(i-c.first)+abs(j-c.second)!=1||i<0||i>=n||j<0||j>=m){ continue;}
                if(mp[i][j]!=1){ continue;}
                if(visited[i][j]){ continue;}
                visited[i][j]=true;
                q.push(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(mp[i][j]==0){cout << "#";}
            else if(mp[i][j]==2){cout << ".";}
            else{cout<<"X";}
        }
        cout << "\n";
    }
}