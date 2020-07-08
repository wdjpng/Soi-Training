#include <bits/stdc++.h>

#define int long long


using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << setprecision(10) << ceil(n/2.0) << "\n";
    }
}