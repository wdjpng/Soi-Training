#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int x, y, z, x1, y1, z1;
    cin >> x >> y >> z >> x1 >> y1 >> z1;
    int a[6];
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }

    int sum = 0;
    if(y<0){sum+=a[0];}
    if(z<0){sum+=a[2];}
    if(x<0){sum+=a[4];}
    if(y1<y){sum+=a[1];}
    if(z1<z){sum+=a[3];}
    if(x1<x){sum+=a[5];}

    cout << sum;
}