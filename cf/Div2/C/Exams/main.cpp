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
    vector<pair<int, int>>in;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a  >> b;
        in.push_back(make_pair(a, b));
    }
    sort(in.begin(), in.end());
    int last=-1;
    for(auto cur : in){
        if(cur.second>=last){last=cur.second;} else{
            last=cur.first;
        }
    }

    cout << last;
}