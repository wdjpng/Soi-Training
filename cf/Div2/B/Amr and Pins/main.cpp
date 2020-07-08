#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    cout << ceil(sqrtf((x1-x2)*(x1-x2)+ (y1-y2) * (y1-y2))/(2*r));
}