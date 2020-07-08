#include <bits/stdc++.h>

#define int long long
using namespace std;

bool can(int n, int s){
    return s <= 9*n && s >= 0;
}
// Used the writeup since my solution had some kind of bug
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    if(!can(n, s) || (n>1&&s==0)){
        cout << "-1 -1";
        exit(0);
    }

    int curS=s;
    for (int i = 0; i < n; ++i) {
        for (int d = 0; d < 10; ++d) {
            if((i>0||d>0||(n==1&&d==0)) && can(n-i-1, curS-d)){
                cout << char('0'+d);
                curS-=d;
                break;
            }
        }
    }

    cout << " ";

    curS=s;
    for (int i = 0; i < n; ++i) {
        for (int d = 9; d >= 0; --d) {
            if((i>0||d>0||(n==1&&d==0)) && can(n-i-1, curS-d)){
                cout << char('0'+d);
                curS-=d;
                break;
            }
        }
    }
}