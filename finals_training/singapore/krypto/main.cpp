#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
    // The following line disables syncing between cin/scanf and cout/printf.
    // It makes input faster, but you must not use functions from <cstdio> (e.g. scanf/printf) directly.
    // This line must be executed before any use of cin/cout.
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int>in(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    vector<int>input=in;
    sort(input.begin(), input.end());
    map<int, int>mp;
    for (int i = 0; i < n; ++i) {
        mp[input[i]]=i;
    }
    for (int i = 0; i < n; ++i) {
        in[i]=mp[in[i]];
    }
    vector<int>fac(1e5+1);
    fac[1]=1;
    for (int i = 2; i < fac.size(); ++i) {
        fac[i]=fac[i-1]*i;
        fac[i]%=(int)1e9+7;
    }

    int sum = 1;
    for (int i = 0; i < n; ++i) {
        if(in[i]<=i){ continue;}
        sum+=(in[i]-i)*fac[n-1-i];
        sum%=(int)1e9+7;
    }

    cout << sum;
}
