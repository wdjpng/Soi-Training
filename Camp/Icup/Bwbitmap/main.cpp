#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> E;
vector<int> color;

const int INF = 1e9+7;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, A, B;
    cin >> n >> k >> A >> B;
    int aToK = 1;
    for (int i = 0; i < k; ++i) {
       aToK*=A;
       aToK%=INF;
    }

    vector<pair<int, int>> memory(n, make_pair(1,0));
    memory[0].first=A+B;
    memory[k].second=memory[0].first;

    cout << memory[k].second << "\n";
    for (int i = 1; i < n-k; ++i) {
        memory[i].first*=(A+B)*memory[i-1].first;
        memory[i].second*=(A+B)*memory[i-1].second;
        memory[i].first%=INF;
        if(i+k < n){
            memory[i+k].second=memory[i].first*aToK;
            memory[i+k].second%=INF;
        }
    }

    cout << memory[n-1].second;
}