#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9+7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    double n, k, A, B;
    cin >> n >> k >> A >> B;
    double z = pow(1.0-pow(A/(A+B), k), n-k+1.0);
    cout << pow(A+B, n) * (1.0-z);

}