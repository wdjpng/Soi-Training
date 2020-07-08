#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int>count(1e7+1);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        count[c]++;
    }
    cin >> m;
    vector<bool>isPrime(1e7+1, true);
    vector<int>f(1e7+1);
    for (int i = 2; i <= 1e7; ++i) {
        if(!isPrime[i]){ continue;}
        for (int j = i; j <= 1e7; j+=i) {
            isPrime[j]=false;
            f[i]+=count[j];
        }
    }

    for (int i = 1; i < f.size(); ++i) {
        f[i]+=f[i-1];
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << f[min((int)1e7, r)]-f[min((int)1e7, l-1)]<<"\n";
    }
}