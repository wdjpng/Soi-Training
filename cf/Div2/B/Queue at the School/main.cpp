#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    string a;
    cin >> a;

    for (int i = 0; i < t; ++i) {
        string newA=a;
        for (int i = 0; i < n-1; ++i) {
            if(a[i] == 'B' && a[i+1] == 'G'){
                newA[i]='G';
                newA[i+1]='B';
            }
        }
        a=newA;
    }

    cout << a;
}