#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

#define int long long
using namespace std;



signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjencyList(n);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adjencyList[start].push_back(end);
        adjencyList[end].push_back(start);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adjencyList[i].size(); ++j) {
            cout << adjencyList[i][j] <<  " ";
        }
        cout << "\n";
    }
}