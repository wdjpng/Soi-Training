#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << min(n, m)+1 << "\n";
    for (int i = 0; i <= min(n, m); ++i) {
        cout << i << " " << min(n, m) - i << "\n";
    }
}