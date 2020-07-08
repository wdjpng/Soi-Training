#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<int> giveMeThePoints(n);
    for (int i = 0; i < n; ++i) {
        cin >> giveMeThePoints[i];
    }

    sort(giveMeThePoints.begin(), giveMeThePoints.end());

    for (int i = 0; i < n; ++i) {
        cout << giveMeThePoints[i] << " ";
    }

    cout << "\n";
}