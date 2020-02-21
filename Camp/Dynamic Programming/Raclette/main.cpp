#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9+7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int>input(n);

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        input[i]%=k;
    }
    sort(input.begin(), input.end());

    vector<vector<int>>memory(n, vector<int>(k)); //index, sum
    memory[0][0] = 1;
    memory[0][input[0]] = 1;

    for (int i = 1; i < n; ++i) {
        for (int curSum = 0; curSum < k; ++curSum) {
            if(memory[i-1][curSum]){
                memory[i][curSum]+=memory[i-1][curSum];
                memory[i][(curSum+input[i])%k]+=memory[i-1][curSum];

                memory[i][curSum]%=MOD;
                memory[i][(curSum+input[i])%k]%=MOD;
            }
        }
    }

    cout << memory[n-1][0];
}