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
        string s;
        cin >> s;

        vector<pair<char, int>> n;
        int count = 1;
        for (int i = 1; i < s.size(); ++i) {
            if(s[i]!=s[i-1]){
                n.push_back(make_pair(s[i-1], count));
                count = 1;
            } else{
                count++;
            }
        }
        n.push_back(make_pair(s[s.size()-1], count));

        int minn=1e9;
        for (int i = 0; i < n.size()-2&&n.size()>2; ++i) {
            if(n[i].first!=n[i+2].first){
                minn=min(minn, (int)n[i+1].second+2);
            }
        }
        if(minn==1e9){minn=0;}
        cout << minn << "\n";
    }
}