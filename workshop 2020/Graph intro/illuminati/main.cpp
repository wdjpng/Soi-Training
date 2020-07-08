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
        for (int j = 0; j < adjencyList[i].size(); ++j) {
            for (int k = 0; k < adjencyList[adjencyList[i][j]].size(); ++k) {
                for (int l = 0; l < adjencyList[adjencyList[adjencyList[i][j]][k]].size(); ++l) {
                    if(adjencyList[adjencyList[adjencyList[i][j]][k]][l] == i){
                        cout << "Illuminati confirmed!\n";
                        exit(0);
                    }
                }
            }
        }
    }

    cout << "That is too far fetched.\n";
}