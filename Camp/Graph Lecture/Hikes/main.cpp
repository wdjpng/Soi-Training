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

    int n, m;
    cin >> n >> m;


    vector<vector<int>>E(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }

    int counter = 0;
    vector<bool>visited(n);
    stack<int>s;
    s.push(0);
    visited[0]=true;

    while (s.size()){
        int cur = s.top();
        s.pop();

        for(int next : E[cur]){
            if(!visited[next]){
                visited[next]=true;
                s.push(next);
            } else{
                counter+=2;
            }
        }
    }

    cout << counter << "\n";
}