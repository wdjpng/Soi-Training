#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

#define int long long
using namespace std;

vector<vector<int>> memory;
vector<int> coins;
vector<bool>solution;
bool subsetsum(int sum, int cur){
    if(sum == 0){
        if(cur > -1){
            solution[cur] = true;
        }
        return true;
    }
    if(cur == -1 || sum < 0){
        return false;
    }
    if(memory[cur][sum] != -1){
        return memory[cur][sum];
    }

    if(!solution[cur]){
        solution[cur] =  subsetsum(sum, cur-1);
    }
    return  memory[cur][sum] = subsetsum(sum-coins[cur], cur-1) || subsetsum(sum, cur-1);
}

signed main() {
    int n, sum;
    cin >> n>>sum;
    memory = vector<vector<int>>(n+1, vector<int>(sum+1, -1));
    coins=vector<int>(n);
    solution=vector<bool>(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    subsetsum(sum, n-1);
    for (int i = 0; i < n; ++i) {
        if(solution[i]){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

}