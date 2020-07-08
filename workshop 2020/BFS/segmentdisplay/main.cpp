#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define int long long
using namespace std;

signed main() {
    int c, x, y;
    cin >> c >> x >> y;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> depth(1000000, -1);
    queue<int> myQueue;
    myQueue.push(x);
    depth[x] = 0;
    int cur = -1;
    while (cur != y){
        cur = myQueue.front();
        myQueue.pop();

        int next1 = (cur*c) % 1000000, next2 = (cur + 1) % 1000000;
        if(depth[next1] == -1){
            myQueue.push(next1);
            depth[next1] = depth[cur] + 1;
        }

        if(depth[next2] == -1){
            myQueue.push(next2);
            depth[next2] = depth[cur] + 1;
        }
    }


    cout << depth[y] << "\n";

}