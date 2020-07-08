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
    vector<pair<int, int>>in(n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        in[i]=make_pair(a,b);
    }
    sort(in.begin(), in.end());

    int maxx = in[0].second;
    int count = 0;
    for (int i = 1; i < n; ++i) {
        if(in[i].second<maxx){count++;}
        maxx=max(maxx, in[i].second);
    }

    cout << count;
}