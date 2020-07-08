#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, piles;
vector<int>a;
vector<bool>used;
bool works(bool b){
    int remain = n/piles+b;
    bool hasSol=true;
    while (remain){
        int c=-1;
        for (int k = n-1; k >= 0; --k) {
            if(used[k]){ continue;}
            if(remain-1<=a[k]){ c=k; used[k]= true; break;}
        }
        if(c==-1){hasSol=false; break;}

        remain--;
    }

    return hasSol;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    cin >> n;
    a=vector<int>(n);


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (piles = 1; piles <= n; ++piles) {
        used=vector<bool>(n);
        bool hasSol=true;
        for (int i = 0; i < n%piles; ++i) {
            hasSol&=works(true);
        }
        for (int i = 0; i < piles-n%piles; ++i) {
            hasSol&=works(false);
        }
        if(hasSol){
            cout << piles;
            exit(0);
        }
    }
}