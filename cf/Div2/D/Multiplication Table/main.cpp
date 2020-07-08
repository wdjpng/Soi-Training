#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int startX=0, endX=1e12;
    while (startX + 1 < endX){
        int curX = (startX+endX)/2;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum+=min(m, (curX)/i);
        }

        if(sum < k){
            startX=curX;
        } else{
            endX=curX;
        }
    }

    cout << endX;
}