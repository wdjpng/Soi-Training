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

    vector<pair<int, int>>input(n);
    for (int i = 0; i < n; ++i) {
        int strength, age;
        cin >> strength >> age;
        input[i]=make_pair(strength, age);
    }
    sort(input.begin(), input.end());

    map<int, int> mp;
    int counter=1;
    mp[input[0].second] = 1;

    for (int i = 1; i < n; ++i) {
        int cur = input[i].second;

        //First lower element
        auto it = mp.lower_bound(cur);
        if(it == mp.begin()){
            counter++;
            mp[cur]++;
        } else{
            it--;
            if(mp[(*it).first] <= 1){
                mp.erase(it);
            } else{
                mp[(*it).first]--;
            }
            mp[cur]++;
        }
    }

    cout << counter;
}