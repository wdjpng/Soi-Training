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

        vector<pair<int, int>>input(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            input[i] = make_pair(a, b);
            sum+=a;
        }

        vector<vector<int>>spar;
        for (int i = 0; i < n-1; ++i) {
            spar.push_back({min(input[i+1].first, input[i].second), i});
        }
        spar.push_back({min(input[0].first, input[n-1].second), n-1});
        sort(spar.begin(), spar.end());
        reverse(spar.begin(), spar.end());



        vector<bool>isDead(n, false);
        for (int i = 0; i < n; ++i) {
            if(!isDead[(spar[i][1]+1)%n]){
                sum-=spar[i][0];
            }
            isDead[spar[i][1]]=true;
        }

        cout << sum << "\n";
    }
}