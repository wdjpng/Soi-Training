#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>


#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> memory(4, vector<int>(n,0));
    for (int i = 0; i < n; ++i) {
        memory[0][i] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        memory[i][0] = 1;
    }

    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int s = 1; s < 4; ++s) {
                if(j < s || i < s){
                    break;
                }
                memory[i][j]+=memory[i-s][j-s];


                for (int i = 0; i < s; ++i) {
                   memory[i][j]
                }
                memory[i][j]%=m;
            }
        }
    }

    cout << memory[3][n-1] << "\n";
}