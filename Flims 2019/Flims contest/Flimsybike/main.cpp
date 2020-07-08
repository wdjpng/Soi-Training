#include <bits/stdc++.h>

#define int long long

using namespace std;
using namespace std;
#define int long long

int n, k, m;

signed main() {
    cin >> n >> k >> m;
    vector<vector<int>> E(n);
    vector<vector<int>> depth(2, vector<int>(n,-1));
    depth[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    int s;
    cin >> s;
    vector<bool>isFlim(n);
    for (int i = 0; i < s; ++i) {
        int x;
        cin >> x;
        isFlim[x]=true;
    }

    queue<vector<int>> queue;
    depth[0][0]=0;
    //Foot or bike, v
    queue.push({0,0});
    while (queue.size()){
        vector<int> cur = queue.front();
        //bike
        int b=cur[0];
        int pos=cur[1];
        queue.pop();

        if(isFlim[pos]){
            for (int w : E[pos]) {
                int add =b?k:1;
                if(depth[!b][w] == -1 || depth[!b][w] > depth[b][pos] + add){
                    depth[!b][w] = depth[b][pos] + add;
                    queue.push({!b, w});
                }
            }
        }

        for (int w : E[pos]) {
            int add = b?1:k;
            if(depth[b][w] == -1 || depth[b][w] > depth[b][pos] + add){
                depth[b][w] = depth[b][pos] + add;
                queue.push({b, w});
            }
        }

    }

    cout << depth[0][n-1];
}