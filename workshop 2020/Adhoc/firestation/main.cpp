#include <bits/stdc++.h>


using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> input(n);
    map<int, bool> isHouse;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        isHouse[input[i]] = true;
    }

    sort(input.begin(), input.end());

    if (floor((input[0] + input[n - 1]) / 2.0) == (input[0] + input[1]) / 2.0) {
        for (int i = 0; i < n; ++i) {
            if (!isHouse[(input[0] + input[n - 1]) / 2 + i]) {
                cout << (input[0] + input[n - 1]) / 2 + i;
                break;
            }
            if (!isHouse[(input[0] + input[n - 1]) / 2 - i]) {
                cout << (input[0] + input[n - 1]) / 2 - i;
                break;
            }
        }
    } else {
        for (int i = 0; i < 2*n; ++i) {
            if (!isHouse[(input[0] + input[n - 1] - 1) / 2 - i]) {
                cout << (input[0] + input[n - 1] - 1) / 2 - i;
                break;
            }
            if (!isHouse[(input[0] + input[n - 1] + 1) / 2 + i]) {
                cout << (input[0] + input[n - 1] + 1) / 2 + i;
                break;
            }
        }
    }
    cout << "\n";
}