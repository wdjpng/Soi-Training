#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

const int MOD = 1e6;

//I think this is nearly exactly gridpath

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >> k;
    vector<vector<int>>possibilities(a, vector<int>(b, -1));

    for (int i = 0; i < a; ++i) {
        possibilities[i][0] = 1;
    }

    for (int i = 0; i < b; ++i) {
        possibilities[0][i] = 1;
    }

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        possibilities[x][y] = 0;
        if(x==0){
            for (int i = y; i < b; ++i) {
                possibilities[0][i] = 0;
            }
        }
        if(y==0){
            for (int i = x; i < a; ++i) {
                possibilities[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < a; ++i) {
        for (int j = 1; j < b; ++j) {
            if(possibilities[i][j] == -1){
                possibilities[i][j]=(possibilities[i-1][j]+possibilities[i][j-1]) % MOD;
            }
        }
    }

    cout << possibilities[a-1][b-1] << "\n";
}