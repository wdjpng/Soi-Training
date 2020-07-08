#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    vector<char>pos={'^', '>', 'v', '<'};
    char c0, c1;
    int i0, i1, spin;
    cin >> c0 >> c1;
    for (int i = 0; i < 4; ++i) {
        if(c0 == pos[i]){
            i0=i;
        }
        if(c1 == pos[i]){
            i1=i;
        }
    }

    cin >> spin;
    spin%=4;
    if((spin+i0)%4 == i1&&(i0-spin+4)%4 != i1){
        cout << "cw";
    } else if((spin+i0)%4 != i1&&(i0-spin+4)%4 == i1){
        cout << "ccw";
    } else{
        cout << "undefined";
    }
}