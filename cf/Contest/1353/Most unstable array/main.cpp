#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        if(n==1){cout<<"0";} else if(n==2){cout << m;} else{
            cout << 2*m;
        }
        cout << "\n";
    }
}