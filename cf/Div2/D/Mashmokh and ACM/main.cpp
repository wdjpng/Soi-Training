#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>>memory(k, vector<int>(n+1, 0));
    vector<vector<int>>divisors(n+1);

    for (int j = 1; j <= n; ++j) {
        for (int l = 1; l <= 64; ++l) {
            if(j%l==0){
                divisors[j].push_back(l);
                if(j/l>64){
                   divisors[j].push_back(j/l);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        memory[0][i]=1;
    }


    for (int i = 1; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for(int divisor : divisors[j]){
                memory[i][j]+=memory[i-1][divisor];
                memory[i][j]%=(int)1e9+7;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum+=memory[k-1][i];
        sum%=(int)1e9+7;
    }

    cout << sum;
}