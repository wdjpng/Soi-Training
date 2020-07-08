#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, n, m;
        cin >> a >> b >> n >> m;

        if(a+b<n+m){
            cout << "No\n";
            continue;
        }
        if(min(a, b)>=m){
            cout << "Yes\n";
            continue;
        }

        n-=abs(a-b);
        if(n<0){
            cout << "No\n";
            continue;
        }

        n-=min(n, m);
        m-=min(n, m);
        if(m<=min(a,b)-min(n, m)){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
}