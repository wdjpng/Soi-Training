#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int>cost;

pair<int, int>winter(int v, int p,vector<vector<pair<int, int>>>&E){
    if(E[v].size()==1&&v!=0){
        return make_pair(max((int)0, cost[v] - E[v][0].second), 2*E[v][0].second);
    }

    int needed=0, remaining=cost[v];
    int parentTime=0;
    vector<pair<int, int>>times;
    for (auto w : E[v]) {
        if(w.first==p){ parentTime=w.second; continue;}
        times.push_back(winter(w.first, v, E));
    }
    sort(times.begin(), times.end());
    reverse(times.begin(), times.end());
    for (auto t : times) {
        needed+=t.second;
        remaining=max((int)0, remaining-t.second);
        remaining+=t.first;
    }
    needed+=2*parentTime;
    remaining=max((int)0, remaining-parentTime);

    return make_pair(remaining, needed);
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    cost=vector<int>(n);
    vector<vector<pair<int, int>>>E(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        E[a].push_back(make_pair(b,c));
        E[b].push_back(make_pair(a,c));
    }

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    pair<int, int>res=winter(0, -1, E);
    cout << res.first + res.second;
}