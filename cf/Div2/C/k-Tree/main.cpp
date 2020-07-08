#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> mem(n + 1, vector<int>(2));
    mem[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int l = 1; l <= k; ++l) {
            if (l + i > n) { break; }
            if (l >= d) {
                mem[i + l][1] += mem[i][0] + mem[i][1];
            } else {
                mem[i + l][1] += mem[i][1];
                mem[i + l][0] += mem[i][0];
            }
            mem[i + l][0] %= MOD;
            mem[i + l][1] %= MOD;
        }
        
    }

    cout << mem[n][1];
}