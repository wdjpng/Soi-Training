#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define int long long
using namespace std;

int dfs(vector<vector<int>>& adjacencyList, int& start, vector<int>& talents, vector<bool>& visited, int& talent){
    queue<int> nodesToVisit;
    nodesToVisit.push(start);
    visited[start] = true;
    
    int counter = 1;
    while (nodesToVisit.size()){
        int cur = nodesToVisit.front();
        nodesToVisit.pop();

        for (int i = 0; i < adjacencyList[cur].size(); ++i) {
            int nextNode = adjacencyList[cur][i];
            
            if(!visited[nextNode] && talents[nextNode-1] < talent){
                visited[nextNode] = true;
                nodesToVisit.push(nextNode);
                counter++;
            }
        }
    }

    return counter;
}
signed main() {
    int n, m, t;
    cin >> n >> m >> t;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjacencyList(n);
    vector<int> stoflTalents(t);
    vector<vector<int>> talents(t, vector<int>(n-1));
    for (int i = 0; i < t; ++i) {
        cin >> stoflTalents[i];
    }

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < t; ++j) {
            cin >> talents[j][i];
        }
    }
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }


    int max = -1;
    int maxTalent;
    for (int talent = 0; talent < t; ++talent) {
        vector<bool>visited(n, false);
        for (int mouse = 1; mouse < adjacencyList.size(); ++mouse) {
            if(talents[talent][mouse -1] < stoflTalents[talent]){
                int cur = dfs(adjacencyList, mouse, talents[talent], visited, stoflTalents[talent]);

                if(cur > max){
                    max = cur;
                    maxTalent = talent;
                }
            }
        }
    }

    cout << maxTalent << " " << max << "\n";

}