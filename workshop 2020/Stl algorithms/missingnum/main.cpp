#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> giveMeThePoints(n);
    for (int i = 0; i < n; ++i) {
        cin >> giveMeThePoints[i];
    }

    sort(giveMeThePoints.begin(), giveMeThePoints.end());

    for (int i = 0; i < 2000005; ++i) {
        if(giveMeThePoints[i] != i + 1){
            cout << i + 1 << "\n";
            break;
        }
    }
}