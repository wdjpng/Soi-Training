#include <bits/stdc++.h>

#define int long long

using namespace std;

// I am not good at naming methods
vector<int>parentsToRemove(int cur, ){

}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(2 * n + 1);
    for (int i = 0; i < m; ++i) {
        string from, to;
        cin >> from >> to;
        int a = 0, b = 0;
        bool isAaset = from[0] == 'A', isBaset = to[0] == 'A';
        for (int i = from.size() - 1; i > 0; --i) {
            a *= 10;
            a += from[i] - '0';
        }
        for (int i = to.size() - 1; i > 0; --i) {
            b *= 10;
            b += to[i] - '0';
        }
        if (isAaset) {
            a += n;
        } else if (isBaset) {
            b += n;
        }
        E[a].push_back(b);
        if (isAaset) {
            a -= n;
        } else {
            a += n;
        }
        if (isBaset) {
            b -= n;
        } else {
            b += n;
        }
        E[b].push_back(a);
    }

    vector<int>parent(2*n+1, -1);
    vector<bool>isImpossible(2*n+1, false);

    for (int i = 0; i < n; ++i) {
        //Parents to remove

    }
}