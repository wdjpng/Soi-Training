#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, r;
        cin >> n >> r;
        int move=0;
        if(r>=n){
            move++;
        }
        r=min(r,n-1);
        move+=r*(r+1)/2;
        cout << move << "\n";
    }
}