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

    for (int i = 0; i <= n/4; i++) {
        int cur = n-i*4;
        if(cur%7){ continue;}
        for (int j = 0; j < i; ++j) {
            cout << "4";
        }
        for (int j = 0; j < (n-4*i)/7; ++j) {
            cout << "7";
        }
        exit(0);
    }

    cout << -1;
}