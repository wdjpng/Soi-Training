#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

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
    int n, sum;
    cin >> n>>sum;
    memory = vector<vector<int>>(n+1, vector<int>(sum+1, -1));
    coins=vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    if(subsetsum(sum, n-1)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}