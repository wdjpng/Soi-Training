#include <bits/stdc++.h>

#define int long long
using namespace std;

const int INF = 1e13;

int n, requiredSize;
int dfs(int i, int j, vector<vector<bool>>&visited, vector<vector<int>>const&map, int curMaxElevation){
    int curCounter = 1;
    stack<pair<int, int>>s;
    s.push(make_pair(i, j));
    visited[i][j]=true;

    while (s.size()){
        pair<int, int> cur = s.top();
        s.pop();

        for (int x = -1; x < 2; ++x) {
            for (int y = -1; y < 2; ++y) {
                if(abs(x) + abs(y) == 2){
                    continue;
                }
                if(x+cur.first<0||y+cur.second<0||x+cur.first>=n||y+cur.second>=n){
                    continue;
                }
                if(!visited[x+cur.first][y+cur.second] && map[x+cur.first][y+cur.second]<=curMaxElevation){
                    if(curCounter == requiredSize){
                        return  curCounter;
                    }
                    curCounter++;
                    visited[x+cur.first][y+cur.second]=true;
                    s.push(make_pair(x+cur.first, y+cur.second));
                }
            }
        }
    }

    return curCounter;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> requiredSize;

    vector<vector<int>>map(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }

    int start = 0, end = 1e9;
    while (start+1 < end){
        int curMaxElevation = (start+end)/2;
        vector<vector<bool>>visited(n , vector<bool>(n, false));
        int maxCounter=0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j){
                if(!visited[i][j] && map[i][j] <= curMaxElevation){
                    maxCounter=max(maxCounter, dfs(i, j, visited, map, curMaxElevation));
                }
            }
        }

        if(maxCounter>=requiredSize){
            end=curMaxElevation;
        } else{
            start=curMaxElevation;
        }
    }

    cout << end<< "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            vector<vector<bool>>visited(n , vector<bool>(n, false));
            if(!visited[i][j] && map[i][j] <= end){
                 if(dfs(i, j, visited, map, end) == requiredSize){
                     visited=vector<vector<bool>>(n, vector<bool>(n, false));
                     dfs(i, j, visited, map, end);
                     for (int y = 0; y < n; ++y) {
                         for (int x = 0; x < n; ++x) {
                             if(visited[y][x]){
                                 cout << "*";
                             } else{
                                 cout << ".";
                             }
                         }
                         cout << "\n";
                     }
                     exit(0);
                 }
            }
        }
    }
}