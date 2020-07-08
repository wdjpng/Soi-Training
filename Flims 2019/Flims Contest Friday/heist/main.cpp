#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int m, n, a, b;
    cin >> m >> n >> a >> b;

    vector<vector<int>>mp(n+1,vector<int>(m+1));
    for (int y = 1; y <= m; ++y) {
        string str;
        cin >> str;
        for (int x = 1; x <= n; ++x) {
            mp[x][y]=mp[x-1][y]+mp[x][y-1]-mp[x-1][y-1];
            if(str[x-1]=='0'){
                mp[x][y]++;
            }
        }
    }

    vector<vector<int>>dectPref(n+1, vector<int>(m+1));
    for (int x = 1; x <= n-b+1; ++x) {
        for (int y = 1; y <= m-a+1; ++y) {
            dectPref[x][y]=mp[x+b-1][y+a-1]-mp[x+b-1][y-1]-mp[x-1][y+a-1]+mp[x-1][y-1]==a*b;
        }
    }

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            dectPref[x][y]+=dectPref[x-1][y]+dectPref[x][y-1]-dectPref[x-1][y-1];
        }
    }


    int count=0;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            int x2 = max((int)0, x-b), y2 = max((int)0, y-a);
            if(dectPref[x][y]-dectPref[x2][y]-dectPref[x][y2]+dectPref[x2][y2]) count++;
        }
    }

    cout << count;
}