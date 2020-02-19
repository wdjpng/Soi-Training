#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

vector<vector<int>> memory;
vector<int> coins;

bool subsetsum(int sum, int cur){
    if(sum == 0){
        return true;
    }
    if(cur == -1 || sum < 0){
        return false;
    }
    if(memory[cur][sum] != -1){
        return memory[cur][sum];
    }

    return  memory[cur][sum] = subsetsum(sum-coins[cur], cur-1) || subsetsum(sum, cur-1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    coins = vector<int>(n);
    int maxHeight = 0;
    int minHeight = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        if(coins[i] > 0){
            minHeight = min(minHeight, coins[i]);
        }
    }

    if(n > 100000){
        int sum = 1;
        for (int i = 1; i < n-1; ++i) {
            if(coins[i] != coins[i-1] && coins[i] > minHeight){
                sum++;
            }
        }

        cout << sum << "\n";
        exit(0);
    }
    memory = vector<vector<int>>(n+3, vector<int>(1002, -1));

    int sum = 1;
    for (int i = 1; i < n-1; ++i) {
        if(coins[i] != coins[i-1] && coins[i] > minHeight){
            sum++;
        }
    }

    if(subsetsum(coins[n-1], min((int)999, n-2))){
        sum--;
    };
    cout << sum << "\n";
    exit(0);
}