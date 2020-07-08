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
    map<string, string>transl;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        transl[a]=b;
    }

    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        if(transl[a].size() < a.size()){
            cout << transl[a] << " ";
        } else{
            cout << a << " ";
        }
    }
}