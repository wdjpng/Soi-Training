#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    if(n==1){
        cout << 0 << "\n";
        exit(0);
    }
    if(n < 4){
        cout << "impossible";
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        if(i%2==0){
            cout << i/2+floor(n/2.0) << " ";
        } else{
            cout << floor(i/2) << " ";
        }
    }
    cout << "\n";
}