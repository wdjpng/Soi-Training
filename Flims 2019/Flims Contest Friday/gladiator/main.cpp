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

    vector<vector<int>>in(n);
    vector<pair<int, int>>sec(n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        in[i]={a,b,i};
        sec[i]={b, i};
    }
    sort(in.begin(),in.end());
    sort(sec.begin(), sec.end());
    vector<int>inv(n);
    for (int i = 0; i < n; ++i) {
        inv[in[i][2]]=i;
    }
    int secR=0;
    int maxR=0;
    vector<int>out(n);
    for (int i = 0; i < n; ++i) {
        maxR=max(maxR, i);
        int maxSecR=in[i][1];
        for (int j = secR; sec[j].first < maxSecR; ++j) {
            maxR=max(maxR, inv[sec[j].second]);
            maxSecR=max(maxSecR, in[inv[sec[j].second]][1]);
        }

        out[in[i][2]]=maxR+1;
    }

    for (int i = 0; i < n; ++i) {
        cout << out[i] << "\n";
    }
}