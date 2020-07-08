#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a>>b>>c>>d;

    int count = 0;
    for (int x = a; x <= b; ++x) {
        int numEqual = min(c, x+c-1)-max(b, d-x+1) +1;
        count+=numEqual*(d-c);
        int n = c-b+1-numEqual;
        count+=n*(n+1)/2;
    }
    cout << count;
}
