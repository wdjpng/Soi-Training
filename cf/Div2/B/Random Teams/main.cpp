#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    int x = (n)%m;
    int sum = (n/m-1)*(n/m)/2;
    cout << (m-x) * sum +  x *(sum+n/m) << " ";
    cout << (n-m)*(n-m+1)/2;
}