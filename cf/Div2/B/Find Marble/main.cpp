#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, s, t;
    cin >> n >> s >> t;
    s--;
    t--;
    vector<int>E(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        E[i]=a-1;
    }

    int c=0;
    vector<bool>visited(n, false);
    while (s!=t&&!visited[s]){
        c++;
        visited[s]=true;
        s=E[s];
    }

    if(visited[s]){cout << -1;} else{
        cout << c;
    }
}