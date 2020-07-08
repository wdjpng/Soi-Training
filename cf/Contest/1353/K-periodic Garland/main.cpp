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
        int n, k;
        cin >> n >> k;
        string a;
        cin >> a;

        int firstOne=n;
        for (int i = 0; i < n; ++i) {
            if(a[i]=='1'){firstOne=i;
                break;}
        }
        vector<int>pref(n+1);
        for (int i = 1; i <= n; ++i) {
            pref[i]=pref[i-1]+a[i-1]-'0';
        }
        int minn = 1e18;
        if(k>=n){minn=0;}
        for (int i = firstOne; i < firstOne+k; ++i) {
            int cur = pref[i];
            int j;
            for (j = i; j < n; j+=k) {
                minn=min(minn, cur+pref[n]-pref[j]);
                if(a[j]=='0'){cur++;}
                cur+=pref[min(n, j+k)]-pref[j+1];
            }
            minn=min(minn, cur);
        }

        cout << minn << "\n";
    }
}