#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;
    pair<int, int>curPos=make_pair(1,1);
    int remain=r*c;
    for (int i = 0; i < k; ++i) {
        int cells = 2;
        if(i==k-1){cells = remain;}
        cout << cells << "\n";
        for (int j = 0; j < cells; ++j) {
            cout << curPos.first << " " << curPos.second << "\n";
            remain--;
            if(curPos.second%2){
                curPos.first++;
                if(curPos.first>r){
                    curPos.first=r;
                    curPos.second++;
                }
            } else{
                curPos.first--;
                if(curPos.first<1){
                    curPos.first=1;
                    curPos.second++;
                }
            }
        }
    }
}