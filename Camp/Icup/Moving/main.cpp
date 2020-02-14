#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> E;
vector<int> color;

void dfs(int node) {
    stack<int>s;
    s.push(node);

    while (s.size()){
        int cur = s.top();
        s.pop();

        for (int nextNode : E[cur]) {
            if (color[nextNode] == -1) {
                color[nextNode] = !color[cur];
                s.push(nextNode);
            } else if (color[nextNode] == color[cur]) {
                cout << "impossible\n";
                exit(0);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    E = vector<vector<int>>(n);
    color = vector<int>(n, -1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        E[x].push_back(y);
        E[y].push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        if(color[i] == -1){
            color[i]=0;
            dfs(i);
        }
    }

    int min = 0, max = n-1;
    for (int i = 0; i < n; ++i) {
        if(color[i]){
            cout << min << " ";
            min++;
        } else{
            cout << max << " ";
            max--;
        }
    }
}