#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int x, y, MOD = (int)1e9+7;
    int n;

    vector<int>mem(100);
    cin >> mem[1] >> mem[2] >> n;

    for (int i = 3; i <= 12; ++i) {
        mem[i]=(mem[i-1]-mem[i-2]+5*MOD)%MOD;
    }
    mem[0]=mem[6];
    cout << (mem[n%12] +  3*MOD)%MOD;
}