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
        int n;
        cin >> n;
        bool hasSOlution = true;
        int curPlay, curFinish;
        cin >> curPlay >> curFinish;
        if(curFinish>curPlay){
            hasSOlution=false;
        }

        for (int i = 1; i < n; ++i) {
            int play, finish;
            cin  >> play >> finish;
            if(play < curPlay || finish < curFinish|| finish > play || (finish-curFinish) > (play-curPlay)){
                hasSOlution=false;
            }
            curFinish=finish;
            curPlay=play;
        }

        if(hasSOlution){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}