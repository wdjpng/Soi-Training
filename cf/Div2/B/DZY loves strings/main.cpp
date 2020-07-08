#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<int>mp(26);
    int maxx = 0;
    for (int i = 0; i < 26; ++i) {
        cin >> mp[i];
        maxx=max(maxx, mp[i]);
    }

    int sum = 0;
    for (int i = 0; i < s.size() + k; ++i) {
        int cur = maxx;
        if(i < s.size()){cur = mp[s[i]-'a'];}

        sum+=cur*(i+1);
    }

    cout << sum;
}