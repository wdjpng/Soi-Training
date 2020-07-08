#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> hugPref(2 * n);

    cin >> a[0];
    hugPref[0] = a[0] * (a[0] + 1) / 2;
    vector<int> pref(2 * n);
    pref[0] = a[0];
    int maxA=0;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        maxA=max(maxA, a[i]);
    }
    if(maxA>=x){
        cout << maxA*(maxA+1)/2-(maxA-x)*(maxA-x+1)/2;
        exit(0);
    }

    for (int i = 1; i < 2 * n; ++i) {
        hugPref[i] = hugPref[i - 1] + a[i % n] * (a[i % n] + 1) / 2;
        pref[i] = a[i % n] + pref[i - 1];
    }

    int maxHugs = 0;
    for (int i = 0; i < n; ++i) {
        int daySubtract = 0;
        if (i > 0) {
            daySubtract = pref[i - 1];
        }
        auto it = lower_bound(pref.begin(), pref.end(), x + daySubtract);

        int lastMonthEnd = a[(it-pref.begin())%n];

        int start = abs(a[i]-lastMonthEnd) + 1;
        int firstMOnthHugs=a[i] * (a[i] + 1) / 2 - (start-1) * (start) / 2;

        int tm=a[(it-pref.begin())%n]-(*it  -x - daySubtract);
        if(tm == 0){tm= a[it-pref.begin()];}
        int  hugsLastMonth =tm + start-1;
        int lastMonthHUgs=(hugsLastMonth) * (hugsLastMonth+1) / 2;
        int otherHugs = hugPref[it - pref.begin() - 1]-hugPref[i];
        int hugs = firstMOnthHugs+lastMonthHUgs+otherHugs;


        maxHugs = max(hugs, maxHugs);
    }

    cout << maxHugs;

}