#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n, A, B;
    cin >> n >> A >> B;
    int tmpA = A;
    A = max(A, B);
    B = min(tmpA, B);

    vector<int> mice(n);
    int sum = 0;
    int aTimesB = A*B;
    for (int i = 0; i < n; ++i) {
        cin >> mice[i];
        sum+=floor(mice[i]/(A*B));
        mice[i]=mice[i]%aTimesB;
    }


    vector<vector<vector<int>>>minCost(n+1, vector<vector<int>>(A, vector<int>(B, 1e10)));
    minCost[0][0][0]=0;
    for (int i = 0; i < n; ++i) {
        for (int curA = 0; curA < A; ++curA) {
            for (int curB = 0; curB < B; ++curB) {
                int x = floor(mice[i]/A);
                int z = mice[i]-x*A;
                int h = floor(mice[i]/B);
                
            }
        }
    }

    for (int cur = 0; cur < ; ++cur) {

    }
    cout << minCost[n][0][0] + sum;
}