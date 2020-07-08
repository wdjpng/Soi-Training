#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define int long long
using namespace std;


signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjencyList(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adjencyList[start].push_back(end);
        adjencyList[end].push_back(start);
    }

    for (int i = 0; i < n; ++i) {
        if(adjencyList[i].size() > 2 || adjencyList[i].size() < 1){
            cout <<  "other\n";
            exit(0);
        }
    }

    cout << "stoflococcus\n";
}