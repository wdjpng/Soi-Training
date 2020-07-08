#include <bits/stdc++.h>

#define int long long
using namespace std;
const int INF = 1e18;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    int firstInput;
    cin >> firstInput;
    mp[firstInput] = 1;
    for (int i = 1; i < n; ++i) {
        int cur;
        cin >> cur;


        auto it = mp.upper_bound(cur);
        auto it2 = it;
        it2--;

        if (it == mp.begin()) {
            mp.erase(mp.begin());
            mp[cur] = 1;
        } else if (it == mp.end() && cur > (*it2).first) {
            mp[cur] = (*it2).second + 1;
        } else if(cur > (*it2).first && cur < (*it).first){
            mp[cur]=(*it).second;
            mp.erase(it);
        }
    }

    auto it = mp.end();
    it--;
    cout << (*it).second;
}