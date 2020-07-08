#include <bits/stdc++.h>

#define int long long

using namespace std;
//This is mainly a joke submission, I think it would be funny if it worked
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>input(n);
    vector<int>maximums(n);
    int maximum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        maximum=max(maximum, input[i]);
        maximums[i]=maximum;
    }

    int maxLost = 0;
    for (int i = n-1; i > 0; --i) {
        maxLost=max(maxLost, maximums[i-1] - input[i]);
    }

    cout << maxLost << "\n";
}