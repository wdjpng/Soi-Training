#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

using namespace std;
#define int long long

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> row(2*n + 1, n);

    for (int y = 0; y < n + 1; ++y) {
        for (int x = 0; x < row.size(); ++x) {
            cout << row[x] << " ";
        }
        cout << "\n";

        for (int i = y+1; i < 2*n - y; ++i) {
            row[i]--;
        }
    }


    for (int y = n-1; y >= 0; --y) {
        for (int i = y+1; i < 2*n - y; ++i) {
            row[i] ++;
        }

        for (int x = 0; x < row.size(); ++x) {
            cout << row[x] << " ";
        }
        cout << "\n";
    }
}