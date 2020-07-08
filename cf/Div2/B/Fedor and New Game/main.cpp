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
    
    vector<int>a(m+1);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    int fedor;
    cin >> fedor;

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int curK = 0;
        for (int j = 0; j < n; ++j) {
            curK+=(a[i] & (1 << (j))) != (fedor & (1 << (j)));
        }

        if(curK <= k){
            sum++;
        }
    }

    cout << sum;
}