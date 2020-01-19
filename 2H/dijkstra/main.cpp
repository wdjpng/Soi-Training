#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define int long long

signed main() {
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int,int>>> E(n);
    vector<int> depth(n, -1);
    depth[0] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a-1].push_back(make_pair(b-1, c));
        E[b-1].push_back(make_pair(a-1, c));
    }

    queue<int> queue;
    queue.push(0);
    while (queue.size()){
        int cur = queue.front();
        queue.pop();

        for (int i = 0; i < E[cur].size(); ++i) {
            if(depth[E[cur][i].first] == -1 || depth[E[cur][i].first] > depth[cur] + E[cur][i].second){
                depth[E[cur][i].first] = depth[cur] + E[cur][i].second;
                queue.push( E[cur][i].first);
            }
        }
    }

    if(depth[n-1] == -1){
        cout << "Impossible\n";
    } else{
        cout << depth[n-1] << "\n";
    }
}