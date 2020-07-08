#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    vector<int>in(3);

    for (int i = 0; i < 3; ++i) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    in[2]=min(2*(in[0]+in[1]), in[2]);

    cout << (in[0]+in[1]+in[2])/3;
}