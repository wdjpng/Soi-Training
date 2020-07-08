#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;
// Not currently working
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t, k;
    cin >> t >> k;

    int n = 1e5+10;
    vector<int>pos(n);
    pos[0]=0;
    pos[1]=1;
    for (int i = 1; i < n; ++i) {
        pos[i]+=pos[i-1];
        if(i >= k){
            pos[i]+=max((int)1, pos[i-k]);
        }
        pos[i]%=MOD;
    }

    for (int i = 1; i < n; ++i) {
        pos[i]+=pos[i-1];
        pos[i]%=MOD;
    }

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (pos[b] - pos[a-1] + MOD)%MOD << "\n";
    }
}