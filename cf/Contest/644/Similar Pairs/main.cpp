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
    for (int curT = 0; curT < t; ++curT) {
        int n; cin >> n;
        vector<int>in(n);
        int a=0, b=0;
        for (int i = 0; i < n; ++i) {
            cin >> in[i];
            a+=in[i]%2==0;
            b+=in[i]%2;
        }
        sort(in.begin(), in.end());

        bool hasJoker=false;
        for (int i = 1; i < n; ++i) {
            if(in[i]-1==in[i-1]){
                hasJoker=true;
            }
        }

        if((a%2==0&&b%2==0)||(a%2==1&&b%2==1&&hasJoker)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}