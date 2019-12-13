#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> sumOfRectangle(n, vector<int>(m));
    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            int curSum;
            cin >> curSum;
            if(y!=0){
                curSum+=sumOfRectangle[x][y-1];
            }
            if(x!= 0){
                curSum+=sumOfRectangle[x-1][y];
            }
            if(x!= 0 && y != 0){
                curSum-=sumOfRectangle[x-1][y-1];
            }
            
            sumOfRectangle[x][y] = curSum;
         }
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int cur = sumOfRectangle[x2][y2];

        if(y1!=0){
           cur-=sumOfRectangle[x2][y1-1];
        }
        if(x1!= 0){
            cur-=sumOfRectangle[x1-1][y2];
        }
        if(x1!= 0 && y1 != 0){
            cur+=sumOfRectangle[x1-1][y1-1];
        }

        cout << cur << "\n";
    }
}