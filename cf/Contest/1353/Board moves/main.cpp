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
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        int s = 0;
        for (int j = 1; j <= n/2; ++j) {
            s+=2*j*j+j;
        }

        cout << 4*s-4*(n/2)*(n/2+1)/2 <<"\n";
    }
}