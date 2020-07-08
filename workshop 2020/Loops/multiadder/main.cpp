#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        sum+=x;
    }

    cout << sum << "\n";
}