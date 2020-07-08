#include <bits/stdc++.h>

#define int long long

using namespace std;
//This is mainly a joke submission, I think it would be funny if it worked
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    priority_queue<pair<int, int>>toLess;
    priority_queue<pair<int, int>>toMuch;
    vector<pair<int, int>>output(n, make_pair(-1,0));
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if(cur < d){
            toLess.push(make_pair(cur-d, i));
        } else if(cur > d){
            toMuch.push(make_pair(d-cur, i));
        }
    }

    while (toLess.size()){
        pair<int, int> curToLess = toLess.top();
        pair<int, int> curToMuch = toMuch.top();
        toLess.pop();
        toMuch.pop();
        output[curToLess.second]=make_pair(curToMuch.second, -curToLess.first);
        curToMuch.first-=curToLess.first;
        if(curToMuch.first < 0){
            toMuch.push(curToMuch);
        } else if (curToMuch.first > 0){
            curToMuch.first=-curToMuch.first;
            toLess.push(curToMuch);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << output[i].first+1 << " " << output[i].second << "\n";
    }
}