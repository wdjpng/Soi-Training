#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<int>lanterns(n);
    for (int i = 0; i < n; ++i) {
        cin >> lanterns[i];
    }

    sort(lanterns.begin(), lanterns.end());

    int maxx = 2*max(lanterns[0], l-lanterns[n-1]);
    for (int i = 1; i < n; ++i) {
        maxx=max(maxx, (lanterns[i]-lanterns[i-1]));
    }

    cout << maxx/2.0;
}