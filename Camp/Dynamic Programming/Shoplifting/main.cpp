#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e12;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> input(n);
    
    for (int i = 0; i < n; ++i) {
        int time, price;
        cin >> time >> price;

        input[i] = make_pair(time, price);
    }


    vector<int> oldMinConst(2*n+1, MAX); //Time left in last index
    vector<int> newMinConst(2*n+1, MAX); //Time left in next index

    oldMinConst[n + min(n, input[0].first)] = input[0].second;
    oldMinConst[n-1] = 0;

    int i = 0;
    for(pair<int, int> cur : input){
        i++;
        if(i==1){ continue;}
        for (int curTime = -n; curTime <= n; ++curTime) {
            if(oldMinConst[curTime+n] != MAX){
                int steal = oldMinConst[curTime+n];
                int buy = oldMinConst[curTime+n] + cur.second;
                newMinConst[curTime+n-1]=min(steal, newMinConst[curTime+n-1]);
                newMinConst[min(curTime+n+cur.first, 2*n)] = min(buy, newMinConst[min(curTime+n+cur.first, 2*n)]);
            }
        }
        oldMinConst=newMinConst;
        newMinConst= vector<int>(2*n+1, MAX);
    }

    int minimum = MAX;
    for (int curTime = 0; curTime <= n; ++curTime) {
        minimum = min(minimum, oldMinConst[curTime+n]);
    }
    cout << minimum << "\n";
}