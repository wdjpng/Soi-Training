#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;


vector<int> coins;


signed main() {
    int n, sum;
    cin >> n >> sum;
    coins = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> reachablePoints = {0};
    vector<int> E(1000*n+1, -1);
    bool hasSolution = false;
    vector<bool>isReachable(sum + 1, false);
    for (int i = 0; i < n && !hasSolution; ++i) {
        for (int j = 0; j < reachablePoints.size() && !hasSolution; ++j) {
            if (reachablePoints[j] + coins[i] <= sum) {
                if(isReachable[reachablePoints[j] + coins[i]]){
                    continue;
                }
                isReachable[reachablePoints[j] + coins[i]] = true;
                reachablePoints.push_back(reachablePoints[j] + coins[i]);

               if(E[reachablePoints[j] + coins[i]] == -1){
                   E[reachablePoints[j] + coins[i]] = reachablePoints[j];
               }

                if (reachablePoints[j] + coins[i] == sum) {
                    hasSolution = true;
                }
            }
        }
    }


    if (hasSolution) {
        cout << "YES\n";
        vector<int> output;
        int lastSum = sum;
        int lastIndex = -1;
        vector<bool>canUse(n, true);
        while (lastSum != 0) {
            for (int i = n-1; i >= 0; --i) {
                if(lastSum - E[lastSum] == coins[i] && canUse[i]){
                    lastIndex = i;
                    canUse[i] = false;
                    break;
                }
            }

            output.push_back(lastIndex+1);
            lastSum-=coins[lastIndex];
        }

        reverse(output.begin(), output.end());

        for (int i = 0; i < output.size(); ++i) {
            cout << output[i] << " ";
        }

    } else {
        cout << "NO\n";
    }
}