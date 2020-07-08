#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n;
    cin >> n;
    vector<int>home(100001);
    vector<int>in;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        home[x]++;
        in.push_back(y);
    }

    for (int i = 0; i < n; ++i) {
        cout << n-1+home[in[i]] << " " <<  n - 1 -home[in[i]] << "\n";
    }
}