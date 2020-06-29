#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
#define double long double
using namespace std;

double distance(pair<int, int> pos1, pair<int, int>pos2){
    return sqrt((pos1.first-pos2.first)*(pos1.first-pos2.first) + (pos1.second-pos2.second)* (pos1.second-pos2.second));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    vector<pair<int, int>>M;
    vector<pair<int, int>>N;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        N.push_back(make_pair(x, y));
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        M.push_back(make_pair(x, y));
    }

    double start = distance(M[0], N[0]);
    double end = 3000;
    while (start+0.0001 < end){
        double leashLength = (start+end)/2.0;

        vector<vector<bool>> visited(n, vector<bool>(m));
        stack<pair<int, int>> stack;
        stack.push(make_pair(0,0));
        bool isSolved = false;
        visited[0][0] = true;
        while (stack.size()){
            pair<int, int> cur = stack.top();
            stack.pop();

            if(cur.first + 1 == n && cur.second + 1 == m){
                isSolved = true;
            }

            for (int humanMove = -1; humanMove < 2; ++humanMove) {
                for (int dogMove = -1; dogMove < 2; ++dogMove) {
                    if(humanMove + cur.first < 0 || dogMove + cur.second < 0){
                        continue;
                    }
                    if(humanMove + cur.first >= n || dogMove + cur.second >= m){
                        continue;
                    }

                    if(!visited[cur.first + humanMove][cur.second + dogMove]){
                        if(distance(N[cur.first + humanMove], M[cur.second + dogMove]) <= leashLength){
                            visited[cur.first + humanMove][cur.second + dogMove] = true;
                            stack.push(make_pair(cur.first + humanMove,cur.second + dogMove));
                        }
                    }
                }
            }
        }

        if(isSolved){
            end = leashLength;
        } else{
            start = leashLength;
        }
    }

    cout << (start+end)/2.0 << "\n";
}