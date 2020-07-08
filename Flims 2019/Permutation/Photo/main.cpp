#include <bits/stdc++.h>

#define int long long


using namespace std;

signed main() {
    string ac;
    int n, r;
    cin >> ac >> n >> r;

    vector<int>fac(21);
    fac[0]=1;

    vector<int>trans(n);
    for (int i = 0; i < n; ++i) {
        trans[i]=i;
    }

    for (int i = 1; i < 21; ++i) {
        fac[i]=fac[i-1]*i;
    }

    if(ac=="CHEESE!"){
        int x;
        cin >> x;
        x--;
        vector<int>a(n);

        for (int i = 0; i < n; ++i) {
            int cur=x/fac[n-1-i];
            x-=cur*fac[n-1-i];
            a[i]=trans[cur];
            for (int j = cur; j < n-1; ++j) {
                trans[j]=trans[j+1];
            }
        }

        cout << n << " ";
        for (int i = 0; i < n; ++i) {
            cout << a[i]+1 << " ";
        }
        exit(0);
    }

    cin >> n;
    int num=1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        for (int j = x+1; j < n; ++j) {
            trans[j]--;
        }
        x=trans[x];
        num+=x*fac[n-i-1];
    }

    cout << num;
}