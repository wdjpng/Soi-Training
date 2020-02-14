#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> map;
    vector<string> funcs(n);
    vector<vector<int>>E(n);
    for (int i = 0; i < n; ++i) {
        string func;
        cin >> func;
        funcs[i] = func;
        map[func] = i;
    }

    for (int i = 0; i < n; ++i) {
        int nCon;
        cin >> nCon;
        for (int j = 0; j < nCon; ++j) {
            string link;
            cin >> link;

            E[i].push_back(map[link]);
        }
    }

    for (int iterations = 0; iterations < 3000000; ++iterations) {

    }
}