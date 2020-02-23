#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e12;

void dfs(vector<vector<int>>& dist, vector<vector<int>>const& E, int start){
    queue<pair<int, int>>q;
    q.push(make_pair(start, 0));

    while (q.size()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int next:E[cur.first]){
            if(dist[next][!cur.second] == MAX){
                dist[next][!cur.second]=dist[cur.first][cur.second]+1;
                q.push(make_pair(next, !cur.second));
            }
        }
    }
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>>distA(n, vector<int>(2, MAX));
    vector<vector<int>>distB(n, vector<int>(2, MAX));
    distA[a-1][0]=0;
    distB[b-1][0]=0;

    vector<vector<int>>E(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }

    dfs(distA, E, a-1);
    dfs(distB, E, b-1);

    int minDist = MAX;
    for (int i = 0; i < n; ++i) {
        minDist=min(minDist, max(distA[i][0], distB[i][0]));
        minDist=min(minDist, max(distA[i][1], distB[i][1]));
    }

   if(minDist==MAX){
       cout << "IMPOSSIBLE\n";
   } else{
       cout << minDist << "\n";
   }
}