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

        int minn=1e18;
        for (int i = 1; i <= sqrt(n); ++i) {
            if(n%i==0){
                if(i<=k){minn=min(minn, n/i);}
                if(n/i<=k){minn=min(minn, i);}
            }
        }

        cout << minn << "\n";
    }
}