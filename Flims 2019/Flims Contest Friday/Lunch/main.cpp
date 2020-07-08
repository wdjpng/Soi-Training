#include <bits/stdc++.h>

#define int long long
using namespace std;

int fast_pow(int a, int pow, int m){
    if(pow==0) return 1;
    int res=(fast_pow(a, pow/2,m));
    res*=res;
    res%=m;
    if(pow%2){res*=a;res%=m;}
    return res;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>>pref(n+1, vector<int>(101));
    for (int i = 0; i < n; ++i) {
        pref[i+1]=pref[i];
        int k;
        cin >> k;
        pref[i+1][k]++;
    }

    for (int curQ = 0; curQ < q; ++curQ) {
        int l, x, m;
        cin >> l >> x >> m;
        int r = min(n, l+x);

        int prod=1;
        for (int i = 0; i <= 100; ++i) {
            prod*=fast_pow(i, pref[r][i]-pref[l][i], m);
            prod%=m;
        }


        cout << prod << "\n";
    }
}