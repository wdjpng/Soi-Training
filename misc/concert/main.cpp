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

    int n, sum = 0;
    cin >> n;
    priority_queue<int>lastDecreasingSize;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        input[i]&=cur;
        vector<int> toAdd;
        while (lastDecreasingSize.size() && -lastDecreasingSize.top() <= cur){
            if( - lastDecreasingSize.top() == cur){
                toAdd.push_back(lastDecreasingSize.top());
            }

            sum++;
            lastDecreasingSize.pop();
        }

        if(lastDecreasingSize.size()){
            sum++;
        }

        for (int j = 0; j < toAdd.size(); ++j) {
            lastDecreasingSize.push(toAdd[j]);
        }

        lastDecreasingSize.push(- cur);
    }

    for (int i = n - 1; i > 0; --i) {
        if(input[i] < input[i-1]){
            sum++;
        }
    }
    cout << sum << "\n";
}