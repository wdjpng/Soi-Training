#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<int>sP(3000), sQ(3000);
    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        sP[a]++;
        sP[b+1]--;
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        sQ[a]++;
        sQ[b+1]--;
    }
    int c = 0;
    for (; l <= r; l++){
        int curp=0, curQ=0;
        for (int i = 0; i <= 1000; ++i) {
            curp+=sP[i];
            curQ+=sQ[i];
            if(curp&&curQ){
                c++;
                break;
            }
        }
        vector<int>copy=sQ;
        for (int i = 1; i < 2999; ++i) {
            sQ[i]=copy[i-1];
        }
        sQ[0]=0;
    }

    cout << c ;
}