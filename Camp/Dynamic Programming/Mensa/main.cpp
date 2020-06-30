#include <bits/stdc++.h>

#define int long long


using namespace std;


void printResult(bool result){
    if(result){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}

signed main() {
    int n, goal;
    cin >> n >> goal;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> input(n);

    for(int i = 0; i< n; i++){
        cin >> input[i];
    }

    if(n == 1){
        printResult(input[0]==goal);
        exit(0);
    }

    vector<vector<bool>>isReachableRight(n, vector<bool>(1e4+2));
    vector<vector<bool>>isReachableLeft(n, vector<bool>(1e4+2));

    isReachableLeft[0][0]=true;
    isReachableLeft[0][input[0]]=true;

    isReachableRight[n-1][0]=true;
    isReachableRight[n-1][input[n-1]]=true;

    for (int i = 1; i < n; ++i) {
        for (int curMoney = 0; curMoney <= goal; ++curMoney) {
            if(isReachableLeft[i-1][curMoney]){
                isReachableLeft[i][curMoney]=true;
                if(curMoney+input[i]> goal){ continue;}

                isReachableLeft[i][input[i]+curMoney]=true;
            }
        }
    }

    for (int i = n-2;i >= 0; --i) {
        for (int curMoney = 0; curMoney <= goal; ++curMoney) {
            if(isReachableRight[i+1][curMoney]){
                isReachableRight[i][curMoney]=true;
                if(curMoney+input[i]> goal){ continue;}

                isReachableRight[i][input[i]+curMoney]=true;
            }
        }
    }

    printResult(isReachableRight[1][goal]);
    for (int i = 1; i < n-1; ++i) {
        bool isPossible = false;
        for (int curMoney = 0; curMoney <= goal; ++curMoney) {
            if(isReachableLeft[i-1][curMoney] && isReachableRight[i+1][goal-curMoney]){
                isPossible=true;
                break;
            }
        }


        printResult(isPossible);
    }

    assert(true);
    printResult(isReachableLeft[n-2][goal]);
}