#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<bool> isTree(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        isTree[t] = true;
    }

    vector<int> possibilities(n + 1);
    possibilities[0] = 1;
    int curSum = 0;
    for (int i = 1; i <= n; ++i) {
        if(i >= a){
            curSum+=possibilities[i-a];
        }
        if (i > b) {
            curSum -= possibilities[i - b - 1];
        }
        curSum=(curSum + MOD)% MOD;

        if(!isTree[i]){
            possibilities[i]=curSum;

        }
    }
    cout << possibilities[n] << "\n";
}