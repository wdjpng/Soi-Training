#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<set<int>>sets(100001);
    vector<int>color(n);
    int minC=1e8;
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
        minC=min(minC, color[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a=color[a-1];b=color[b-1];
        if(a==b){ continue;}
        sets[a].insert(b);
        sets[b].insert(a);
    }

    int maxx=0;
    int col=minC;
    for (int i = 1; i < 100001; ++i) {
        if(sets[i].size()==0){ continue;}
        if(sets[i].size() >= maxx){
            if(maxx==sets[i].size()){
                col=min(col, i);
            } else{
                col=i;
            }
            maxx=sets[i].size();
        }
    }

    cout << col;
}