#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

#define int long long
using namespace std;


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(k==0){
        int max = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            if(x > max){
                max = x;
            }
        }

        cout << max;
        exit(0);
    }

    priority_queue<int, vector<int>,greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        pq.push(x);

        if(pq.size() > k + 1){
            pq.pop();
        }
    }

    cout << pq.top() << "\n";
}
