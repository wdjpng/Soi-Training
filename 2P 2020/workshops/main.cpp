#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, j;
    cin >> n >> j;
    int start = 0, end = 1e10;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    while (start + 1 < end) {
        int curWorkshops = (start + end) / 2;
        int curJokers = 0;
        for (int i = 0; i < n; ++i) {
            curJokers += max((int) 0, a[i] * curWorkshops - b[i]);
            if (curJokers > j) {
                end = curWorkshops;
            }
        }

        start = curWorkshops;

    }

    int curWorkshops = start + 1;
    int curJokers = 0;
    for (int i = 0; i < n; ++i) {
        curJokers += max((int) 0, a[i] * curWorkshops - b[i]);
    }
    if (curJokers <= j) {
        start = curWorkshops;
    }


    cout << start << "\n";
}