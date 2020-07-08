#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int x, y;
    cin >> x >> y;

    if (x == y) {
        if (x % 2 == 0) {
            cout << 2 * x << "\n";
        } else {
            cout << 2 * x - 1 << "\n";
        }
    } else if (x - 2 == y) {
        if (y % 2 == 1) {
            cout << 2 * y + 1<< "\n";
        } else {
            cout << 2 * y + 2 << "\n";
        }
    } else {
        cout << "Never\n";
    }
}