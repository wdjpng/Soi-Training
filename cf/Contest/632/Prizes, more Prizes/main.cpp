#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>prize(n);
    for (int i = 0; i < n; ++i) {
        cin >> prize[i];
    }
    
    vector<int>cost(5);
    vector<int>buy(5, 0);
    for (int i = 0; i < 5; ++i) {
        cin >> cost[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=prize[i];
        for (int i = 4; i >= 0; --i) {
            int m=sum/cost[i];
            sum-=m*cost[i];
            buy[i]+=m;
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << buy[i] << " ";
    }
    cout << "\n";
    cout << sum;
}