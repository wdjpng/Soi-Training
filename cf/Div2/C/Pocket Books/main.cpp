#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = 1;
    for (int i = 0; i < m; ++i) {
        vector<bool>occur(26);
        for (int j = 0; j < n; ++j) {
            occur[a[j][i]-'A']=true;
        }
        int tmp=0;
        for (int i = 0; i < 26; ++i) {
            tmp+=occur[i];
        }

        sum*=tmp;
        sum%=(int)1e9+7;
    }

    cout << sum;
}