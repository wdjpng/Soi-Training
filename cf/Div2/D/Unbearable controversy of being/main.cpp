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

    vector<vector<int>>E(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[a-1].push_back(b-1);
    }


    int sum = 0;
    for (int i = 0; i < n; ++i) {
        vector<int>hits(n, 0);
        for (int next : E[i]) {
            for (int next2 : E[next]) {
                if(next2==i){ continue;}
                hits[next2]++;
            }
        }

        for(int hit : hits){
            sum+=hit*(hit-1)/2;
        }
    }

    cout << sum;
}