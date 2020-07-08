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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if((n/b!=m/a||n%b||m%a)){
            cout << "NO\n";
            continue;
        }

        vector<vector<bool>>matrix(m, vector<bool>(n));
        for (int off = 0; off < m/a; ++off) {
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    matrix[i+a*off][j+b*off]=1;
                }
            }
        }

        cout << "YES\n";
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                cout << matrix[i][j];
            }
            cout << "\n";
        }
    }
}