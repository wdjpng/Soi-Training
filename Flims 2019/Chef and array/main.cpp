#include <bits/stdc++.h>

#define int long long


using namespace std;

signed main() {
    int n, q;
    cin >> n;
    vector<vector<int>>rmq(20, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> rmq[0][i];
    }

    for (int p = 1; (1<<p) <= n; ++p) {
        for (int i = 0; (i+ (1<<p)-1) <= n; ++i) {
            rmq[p][i]=max(rmq[p-1][i], rmq[p-1][i+(1<<(p-1))]);
        }
    }

    cin >> q;
    int l, r;
    cin >> l >> r;

    for (int i = 0; i < q; ++i) {
        int k = 0;
        int pow=1;
        while (2*pow<=r-l){
            pow*=2;
            k++;
        }

        cout << max(rmq[k][l], rmq[k][r-(1<<k)+1]) << "\n";
        l=(l+7)%(n-1);
        //TODO r=(r)
    }
}