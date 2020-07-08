#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, p;
    string a;

    cin >> n >> p >> a;
    p--;
    if(p>=n/2){
        p=n-1-p;
    }
    int s=0;
    int firstC=-1, lastC=p;
    for (int i = 0; i < n/2; ++i) {
        if(a[i]!=a[n-i-1]){
            if(firstC==-1){firstC=i;}
            lastC=i;
        }
    }
    if(firstC==-1){
        cout << 0;
        exit(0);
    }
    if(p<firstC){s+=firstC-p;p=firstC;}
    if(p>lastC){s+=p-lastC;p=lastC;}
    s+=min(p-firstC+lastC-firstC, lastC-p+lastC-firstC);
    for (int i = firstC; i <= lastC; ++i) {
        s+=min(abs(a[i]-a[n-i-1]), 26-abs(a[i]-a[n-i-1]));
    }

    cout << s;
}