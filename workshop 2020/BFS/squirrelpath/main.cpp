#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long
using namespace std;


signed main() {
    int n, m, a, b, s;
    cin >> n >> m >> a >> b >> s;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> adjencyList(n);
    vector<int> trees(a);
    vector<int> holes(b);

    for (int i = 0; i < a; ++i) {
        cin >> trees[i];
    }

    for (int i = 0; i < b; ++i) {
        cin >> holes[i];
    }

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        adjencyList[start].push_back(end);
        adjencyList[end].push_back(start);
    }


    vector<int> distancesdTree(n, -1);
    vector<int> distancesHide(n, -1);
    queue<int> myQueue;
    distancesdTree[s] = 0;
    myQueue.push(s);
    while (myQueue.size()){
        int cur = myQueue.front();
        myQueue.pop();

        for (int i = 0; i < adjencyList[cur].size(); ++i) {
            int nextNode = adjencyList[cur][i];

            if(distancesdTree[nextNode] == -1){
                distancesdTree[nextNode] = distancesdTree[cur] + 1;
                myQueue.push(nextNode);
            }
        }
    }

    for (int i = 0; i < a; ++i) {
        myQueue.push(trees[i]);
        distancesHide[trees[i]] = distancesdTree[trees[i]];
    }

    while (myQueue.size()){
        int cur = myQueue.front();
        myQueue.pop();

        for (int i = 0; i < adjencyList[cur].size(); ++i) {
            int nextNode = adjencyList[cur][i];

            if(distancesHide[nextNode] == -1 || distancesHide[cur] + 1 < distancesHide[nextNode]){
                distancesHide[nextNode] = distancesHide[cur] + 1;
                myQueue.push(nextNode);
            }
        }
    }

    int min = numeric_limits<int>::max();
    for (int j = 0; j < b; ++j) {
        if(min > distancesHide[holes[j]]){
            min = distancesHide[holes[j]];
        }
    }

    cout << min << "\n";
}