#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define int long long
using namespace std;

bool isValidPosition(int x, int y, int& n){
    if(x < 0 || y < 0 || x >= n || y >= n){
        return false;
    }

    return true;
}
signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k, m;
    cin >> n >> k  >> m;


    vector<vector<bool>> isSquareDefended(n, vector<bool>(n, false));
    vector<pair<int, int>> knights;
    int counter = k;

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;

        knights.push_back({x, y});
        isSquareDefended[x][y] = true;
    }

    for (int i = 0; i < m; ++i) {
        vector<pair<int, int>> newKnights;
        for (int j = 0; j < knights.size(); ++j) {
            for (int y = -2; y < 5; y+=4) {
                for (int x = -1; x < 2; x+=2) {
                    if(isValidPosition(knights[j].first + x, knights[j].second + y, n)){
                        if(!isSquareDefended[knights[j].first + x][knights[j].second + y]){
                            isSquareDefended[knights[j].first + x][knights[j].second + y] = true;
                            newKnights.push_back({knights[j].first + x, knights[j].second + y});
                            counter++;
                        }
                    }
                }
            }
            for (int x = -2; x < 5; x+=4) {
                for (int y = -1; y < 2; y+=2) {
                    if(isValidPosition(knights[j].first + x, knights[j].second + y, n)){
                        if(!isSquareDefended[knights[j].first + x][knights[j].second + y]){
                            isSquareDefended[knights[j].first + x][knights[j].second + y] = true;
                            newKnights.push_back({knights[j].first + x, knights[j].second + y});
                            counter++;
                        }
                    }
                }
            }
        }
        knights = newKnights;
    }

    /*for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            if(isSquareDefended[x][y]){
                cout << "X";
            } else{
                cout << "_";
            }
        }
        cout<< "\n";
    }*/

    cout <<  counter <<"\n";
}