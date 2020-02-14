#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string>cave(n);
    vector<vector<pair<int, int>>>memory(n, vector<pair<int, int>>(m, make_pair(0,0)));
    memory[0][0].first=1;

    for (int i = 0; i < n; ++i) {
        cin >> cave[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(cave[i][j] == '.'){
                if(i!=0){
                    memory[i][j].first+=memory[i-1][j].first;
                    memory[i][j].second+=memory[i-1][j].second;
                }
                if(j!= 0){
                    memory[i][j].first+=memory[i][j-1].first;
                    memory[i][j].second+=memory[i][j-1].second;
                }
            } else{
                if(i!=0){
                    memory[i][j].second+=memory[i-1][j].first;
                }
                if(j!= 0){
                    memory[i][j].second+=memory[i][j-1].first;
                }
            }
            memory[i][j].first%=1000000007;
            memory[i][j].second%=1000000007;
        }
    }

    cout << (memory[n-1][m-1].first + memory[n-1][m-1].second)%1000000007 << "\n";
}