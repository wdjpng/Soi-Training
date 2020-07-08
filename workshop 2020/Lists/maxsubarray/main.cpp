#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <math.h>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<int> sum(n);
    cin >> sum[0];
    for (int i = 1; i < n; ++i) {
        cin >> sum[i];
        sum[i]+=sum[i-1];
    }

    int max = numeric_limits<int>::min();
    int minSum = 0;
    for (int i = 0; i < n; ++i) {
        if(sum[i] < minSum){
            minSum = sum[i];
        }

        if(sum[i] - minSum > max){
            max = sum[i] - minSum;
        }
    }

    cout << max << "\n";
}