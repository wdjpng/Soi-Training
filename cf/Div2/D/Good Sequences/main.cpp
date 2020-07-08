#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>>in;
    vector<vector<int>>div(1e5+1);
    vector<int>primes;
    for (int i = 2; i <= 1e5; ++i) {
        for(int p : primes){
            if(p>400){ break;}
            if(i%p==0){div[i].push_back(p);

            if(div[i/p].size()==0){
                div[i].push_back(i/p);
            }}
        }
        if(!div[i].size()){primes.push_back(i);}
    }

    vector<int>mem(1e5+1, 0);
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;

        if(div[cur].size()==0&&cur!=1){
            mem[cur]++;
        }
        int newV=0;
        for (int j = 0; j < div[cur].size(); ++j) {
            newV=max(newV, mem[div[cur][j]]+1);
        }

        for (int j = 0; j < div[cur].size(); ++j) {
            mem[div[cur][j]]=newV;
        }
    }

    cout <<  max((int)1, *max_element(mem.begin(), mem.end()));
}