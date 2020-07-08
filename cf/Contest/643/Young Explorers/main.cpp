#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

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
        vector<int>e(n);
        for (int i = 0; i < n; ++i) {
            cin >> e[i];
        }
        sort(e.begin(), e.end());
        int curMin=1, count=0, curCount=0;
        for (int i = 0; i < n; ++i) {
            curMin=max(curMin, e[i]);
            curCount++;
            if(curCount>=curMin){
                count++;
                curCount=0;
                curMin=1;
            }
        }
        cout << count << "\n";
    }
}