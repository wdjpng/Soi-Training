#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        vector<vector<bool>>matrix(n, vector<bool>(n));
        int curK=0;
        int curHori=0;
        vector<bool>usedDia(n);
        while (curK!=k){
            if(curHori==n){
                curHori=0;
                usedDia=vector<bool>(n);
            }
            for (int i = 0; i < n; ++i) {
                if(!usedDia[i]&&!matrix[curHori][i]){
                    matrix[curHori][i]=true;
                    usedDia[i]=true;
                    break;
                }
            }
            curHori++;
            curK++;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j];
            }
            cout << "\n";
        }
    }
}