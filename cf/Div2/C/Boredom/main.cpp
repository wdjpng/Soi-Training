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
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        mp[c]++;
    }

    vector<int> mem(mp.size() + 2);
    int last = -1;
    int i = 2;
    for (auto it = mp.begin(); mp.end() != it; it++) {
        if ((*it).first - 1 != last) { mem[i] = mem[i - 1] + (*it).second*(*it).first; }
        else {
            mem[i] = max(mem[i - 2] + (*it).second*(*it).first, mem[i - 1]);
        }
        last=(*it).first;
        i++;
    }

    cout << mem[mem.size() - 1];
}