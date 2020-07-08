#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

#define int long long

using namespace std;

void colorGraph(int const& start, vector<int>& colors, vector<vector<int>> const& E) {
    stack<int> toVisit;
    toVisit.push(start);

    while (toVisit.size()){
        int cur = toVisit.top();
        toVisit.pop();

        for (int i = 0; i < E[cur].size(); ++i) {
            int toCompare = E[cur][i];
            if(colors[toCompare] == -1){
                toVisit.push(toCompare);
                colors[toCompare] = !colors[cur];
            } else if(colors[cur] == colors[toCompare]){
                cout << "NO\n";
                exit(0);
            }
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> E(n);
    vector<int> colors(n, -1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if(colors[i] == -1){
            colors[i] = 0;
            colorGraph(i, colors, E);
        }
    }

    cout << "YES\n";
}