#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t;
    cin >>t;
    for (int curT = 0; curT < t; ++curT) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int curTime=b;
            int toSleep=a-b;
            if(toSleep<=0){
                cout << curTime << "\n";
                continue;
            }
            long double sleep = c-d;
            if(sleep <=0){
                cout << "-1\n";
                continue;
            }
            int f =(int) c*ceil(toSleep/sleep);
            cout << curTime +  f << "\n";
    }
}