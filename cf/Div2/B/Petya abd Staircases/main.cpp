#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int>in(m);
    for (int i = 0; i < m; ++i) {
        cin >> in[i];
        if(in[i]==n||in[i]==1){
            cout << "NO";
            exit(0);
        }
    }

    sort(in.begin(), in.end());
    for (int i = 0; i < m-2; ++i) {
        if(in[i]+1==in[i+1]&&in[i+1]+1==in[i+2]){
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
}