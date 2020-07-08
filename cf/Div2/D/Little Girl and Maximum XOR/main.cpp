#include <bits/stdc++.h>

#define int long long

int l, r;
int ret = 0LL;
int br = 1;
int poz = 0;

using namespace std;

using namespace std;

signed main() {
    int l, r;
    cin >> l >> r;
    for (int i = 63; i >= 0; --i) {
        if(l >> i != r >> i){
            int z = 1;
            for (int j = 0; j <= i; ++j) {
                z*=2;
            }
            cout << z-1 << "\n";
            exit(0);
        }
    }

    cout << 0;
}