#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string a;
    cin >> a;
    int n = a.size();
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        sol[i] = a[i] - '0';
    }

    int z = sol[n - 1];
    for (int i = 0; i < n; ++i) {
        if ((i == 0 && sol[n - 1] == 0) || sol[i] % 2) { continue; }
        if (sol[i] < sol[n - 1]) {
            sol[n - 1] = sol[i];
            sol[i]=z;
            for (int i = 0; i < n; ++i) {
                cout << sol[i];
            }
            exit(0);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if ((i == 0 && sol[n - 1] == 0) || sol[i] % 2) { continue; }
        sol[n - 1] = sol[i];
        sol[i]=z;
        for (int i = 0; i < n; ++i) {
            cout << sol[i];
        }
        exit(0);
    }

    cout << -1;
}