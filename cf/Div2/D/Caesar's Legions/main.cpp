#include <bits/stdc++.h>

#define int long long
using namespace std;
int n1, n2, k1, k2;
const int MOD = 1e8;
int mem[101][101][11][11];

int recurse(int foot, int horse, int curK1, int curK2) {
    if (foot < 0 || horse < 0 || curK1 > k1 || curK2 > k2) { return 0; }
    if (foot + horse == 0) { return 1; }

    if (mem[foot][horse][curK1][curK2] != -1) {
        return mem[foot][horse][curK1][curK2];
    }

    return mem[foot][horse][curK1][curK2] =
                   (recurse(foot - 1, horse, curK1 + 1, 0) +
                    recurse(foot, horse - 1, 0, curK2 + 1)) % MOD;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n1 >> n2 >> k1 >> k2;
    memset(mem, -1, sizeof mem);

    cout << recurse(n1, n2, 0, 0);
}