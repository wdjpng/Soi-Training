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
    vector<vector<int>>E(m);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        E[i]={w, a-1 , b-1};
    }

    sort(E.begin(), E.end());
    vector<int>maxDepth(n, 0);
    for (int i = 0; i < m; ++i) {
        int firstDifferentElement = m;
        for (int j = i; j < m; ++j) {
            if(E[i][0] != E[j][0]){
                firstDifferentElement=j;
                break;
            }
        }

        vector<vector<int>>updates;
        for (; i < firstDifferentElement; ++i) {
            updates.push_back({E[i][2], maxDepth[E[i][1]] + 1});
        }
        i--;

        for(auto update : updates){
            maxDepth[update[0]]=max(maxDepth[update[0]],  update[1]);
        }
    }

    int maximum = 1;
    for(int depth : maxDepth){
        maximum=max(depth, maximum);
    }

    cout << maximum;
}