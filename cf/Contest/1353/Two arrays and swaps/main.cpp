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
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        vector<int>b(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int l = 0; l < n; ++l) {
            cin >> b[l];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        for (int m = 0; m < k; ++m) {
            if(a[m]>b[m]){ break;}
            a[m]=b[m];
        }
        int s = 0;
        for (int i1 = 0; i1 < n; ++i1) {
            s+=a[i1];
        }

        cout << s << "\n";
    }
}