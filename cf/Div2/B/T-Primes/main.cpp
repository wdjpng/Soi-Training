#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        int b = (int) sqrtf(a);
        bool hasSolution=true;
        if (b * b != a||a==1) {
            cout << "NO\n";
            continue;
        }
        for (int j = 2; j <= 1000; ++j) {
            if (b % j == 0&&j<b) {
                cout << "NO\n";
                hasSolution=false;
                break;
            }
        }

        if(!hasSolution){ continue;}
        cout << "YES\n";
    }
}