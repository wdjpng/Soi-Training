#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n, m;
    cin >> m >> n;
    vector<vector<int>>b(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    vector<vector<bool>>a(m, vector<bool>(n, true));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(b[i][j]){ continue;}
            for (int k = 0; k < n; ++k) {
                a[i][k]=false;
            }

            for (int k = 0; k < m; ++k) {
                a[k][j]=false;
            }
        }
    }

    vector<vector<int>>b1(m ,vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(a[i][k]){b1[i][j]=1;}
            }

            for (int k = 0; k < m; ++k) {
                if(a[k][j]){b1[i][j]=1;}
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(b[i][j]==b1[i][j]){ continue;}
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j]<< " ";
        }
        cout << "\n";
    }
}