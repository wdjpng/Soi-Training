#include <bits/stdc++.h>

#define int long long


using namespace std;

//Has a unnecessary constant factor of 2 but is still fast enough to score 100 points

signed main() {
    int n, c;
    cin >> c >> n;

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> strength(n);

    for (int i = 0; i < n; i++) {
        cin >> strength[i];
    }

    sort(strength.begin(), strength.end());

    int remainingC = c;

    for (int j = 0; j < c; ++j) {
        if (strength[j] < 0) {
            remainingC--;
            strength[j] = -strength[j];
        } else {
            break;
        }
    }

    sort(strength.begin(), strength.end());

    if (remainingC % 2 == 1) {
        strength[0] = -strength[0];
    }

    int sum = 0;
    for (int k = 0; k < strength.size(); ++k) {
        sum += strength[k];
    }

    cout << sum << "\n";
}

