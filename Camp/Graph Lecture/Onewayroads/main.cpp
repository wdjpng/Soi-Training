#include <bits/stdc++.h>

#define int long long
using namespace std;

const int INF = 1e13;

signed main() {
    int n, m;
    vector<vector<int>>E(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        E[a].push_back(b);
        E[b].push_back(a);
    }

    int counter = 0;
    vector<int>depth(n, INF);
    depth[0]=0;
    stack<int>nodes;
    stack<pair<int, int>>backEdges; //lowest,heighest node depth
    nodes.push(0);

    while (nodes.size()){
        int cur = nodes.top();
        nodes.pop();
        while (backEdges.size() && backEdges.top().first >= depth[cur]){
            backEdges.pop();
        }

        for (int nextNode : E[cur]) {
            if(depth[nextNode] == INF){
                depth[nextNode]=depth[cur]+1;
                nodes.push(nextNode);
            } else{
                while (backEdges.size() && backEdges.top().second <= depth[nextNode]){
                    backEdges.pop();
                    counter++;
                }

                int numberOfEdgesToFlip = depth[nextNode] - depth[cur];
                if (backEdges.size()){
                    numberOfEdgesToFlip=min(numberOfEdgesToFlip, backEdges.top().second)
                }

            }
        }
    }
}