#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define int long long
using namespace std;


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    int root = 0;
    vector<vector<int>>E(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        E[a].push_back(b);
        if(E[a].size() > 1){
            root = a;
        }
    }

    priority_queue<int> priorityQueue;

    for(int i = 0; i < E[root].size(); ++i) {
        int maxDepth = 1;
        queue<pair<int, int>> queue;
        queue.push(make_pair(E[root][i], 1));

        while (queue.size()){
            int cur = queue.front().first;

            for (int j = 0; j < E[cur].size(); ++j) {
                queue.push(make_pair(E[cur][j], queue.front().second+1));

                maxDepth = max(maxDepth, queue.front().second+1);
            }
            queue.pop();
        }

        priorityQueue.push(maxDepth);
    }

    while (priorityQueue.size() > 2){
        priorityQueue.pop();
    }

    int sum = priorityQueue.top();
    priorityQueue.pop();
    sum+=priorityQueue.top();

    cout << sum << "\n";
}