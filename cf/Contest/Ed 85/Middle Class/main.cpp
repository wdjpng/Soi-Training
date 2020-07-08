#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int curT = 0; curT < t; ++curT) {
        int n, x;
        cin >> n >> x;

        int sumOverX = 0;
        int richCounter = 0;
        vector<int>poor;
        for (int i = 0; i < n; ++i) {
            int cur;
            cin >> cur;

            if(cur < x){
                poor.push_back(x-cur);
            } else{
                richCounter++;
                sumOverX+=cur-x;
            }
        }

        sort(poor.begin(), poor.end());
        for (int i = 0; i < poor.size(); ++i) {
            if(sumOverX - poor[i] < 0){ break;}
            sumOverX-=poor[i];
            richCounter++;
        }

        cout << richCounter << "\n";
    }
}