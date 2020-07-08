#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    pair<int, int> start;
    vector<vector<char>> input(m, vector<char>(n));
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            cin >> input[x][y];
            if(input[x][y] == 's'){
                start = {x, y};
            }
        }
    }

    queue<pair<int, int>> nodesToVisit;
    nodesToVisit.push(start);
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    while (nodesToVisit.size()){
        pair<int, int> cur = nodesToVisit.front();
        nodesToVisit.pop();

        vector<pair<char, pair<int, int>>> newNodes;
        if(cur.first != 0){
            if(input[cur.first-1][cur.second] != '#'){
                newNodes.push_back({input[cur.first-1][cur.second], {cur.first-1, cur.second}});
            }
        }

        if(cur.second != 0){
            if(input[cur.first][cur.second - 1] != '#'){
                newNodes.push_back({input[cur.first][cur.second - 1], {cur.first, cur.second-1}});
            }
        }

        if(cur.first < m - 1){
            if(input[cur.first+1][cur.second] != '#'){
                newNodes.push_back({input[cur.first+1][cur.second], {cur.first+1, cur.second}});
            }
        }

        if(cur.second < n - 1){
            if(input[cur.first][cur.second + 1] != '#'){
                newNodes.push_back({input[cur.first][cur.second + 1], {cur.first, cur.second + 1}});
            }
        }

        for (int i = 0; i < newNodes.size(); ++i) {
            if(newNodes[i].first == 't'){
                cout << "Go\n";
                exit(0);
            }

            if(!visited[newNodes[i].second.first][newNodes[i].second.second]){
                visited[newNodes[i].second.first][newNodes[i].second.second] = true;
                nodesToVisit.push({newNodes[i].second.first, newNodes[i].second.second});
            }
        }
    }

    cout << "Oh no!\n";

}