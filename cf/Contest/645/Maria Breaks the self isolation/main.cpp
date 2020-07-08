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
    for (int curT = 0; curT < t; ++curT) {
        int n;
        cin >> n;
        vector<int>in(n);
        for (int i = 0; i < n; ++i) {
            cin >> in[i];
        }
        sort(in.begin(), in.end());
        int maxI = -1;
        for (int i = 0; i < n; ++i) {
            if(i+1>=in[i]){
                maxI=i;
            }
        }

        cout << maxI+2 << "\n";
    }
}