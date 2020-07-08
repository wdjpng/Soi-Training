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

    map<pair<int, int>, int> mp;
    int sum = 0, counter = 0;
    int shift = 0;
    int a1;
    cin >> a1;
    mp[make_pair(0, a1)]++;
    int curSumFromOtherSide
    for (int i = 1; i < n; ++i) {
        int cur;
        cin >> cur;
        sum += cur;


    }
}