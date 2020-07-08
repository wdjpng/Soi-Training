#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << min(i, j) << " ";
        }
        cout << "\n";
    }
}