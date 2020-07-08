#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int curT = 0; curT < t; ++curT) {
        int n;
        cin >> n;
        vector<vector<bool>>visited(n,vector<bool>(n));
        vector<vector<int>>matrix(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            string a;
            cin >> a;
            for (int j = 0; j < n; ++j) {
                matrix[j][i]=a[j]=='1';
            }
        }

        bool hasSol=true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j]){
                    pair<int, int>cur=make_pair(i, j);
                    while(cur.first<n-1&&cur.second<n-1){
                        if(matrix[cur.first][cur.second+1]){
                            cur=make_pair(cur.first, cur.second+1);
                        } else if(matrix[cur.first+1][cur.second]){
                            cur=make_pair(cur.first+1, cur.second);
                        } else{
                            hasSol=false;
                            break;
                        }
                    }
                }
            }
        }

        if(hasSol){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}