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

    if(n==1){
        cout << "star\n";
        exit(0);
    } else if((adjencyList[0].size() != 1 && adjencyList[1].size() != 1) || adjencyList[0].size()==0 || adjencyList[1].size() == 0){
        cout << "other\n";
        exit(0);
    }

    if(n == 2){
        if(adjencyList[0].size() == 1 && adjencyList[1].size() == 1){
            cout << "star\n";
            exit(0);
        } else{
            cout << "other\n";
            exit(0);
        }
    }

    int centralNode = -1;
    for (int i = 0; i < adjencyList[0].size(); ++i) {
        for (int j = 0; j < adjencyList[1].size(); ++j) {
            for (int k = 0; k < adjencyList[2].size(); ++k) {
                if(adjencyList[0][i] == adjencyList[1][j]){
                    centralNode = adjencyList[0][i];
                } else if (adjencyList[0][i] == adjencyList[2][k]){
                    centralNode = adjencyList[0][i];
                } else if(adjencyList[1][j] == adjencyList[2][k]){
                    centralNode = adjencyList[1][j];
                }
            }
        }
    }

    if(centralNode == -1){
        cout << "other\n";
        exit(0);
    }

    for (int i = 0; i < n; ++i) {
        if(((adjencyList[i].size() != 1) || (adjencyList[i][0] != centralNode))  && i != centralNode){
            cout << "other\n";
            exit(0);
        }
    }

    cout << "star\n";
}