#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, r;

bool canDo(vector<vector<int>> &v, int curTime, bool shouldPrint) {
    int timeGone = 0;
    string output;
    for (int i = 0; i < v.size(); ++i) {
        int timeToDry = max((int) ceil((v[i][1] - v[i][0]) / (r - 1.0)), (int) 0);
        output += to_string(timeGone) + " " + to_string(v[i][2] + 1) + "\n";
        timeGone += timeToDry;
        if (timeGone > curTime || timeGone > v[i][0]) {
            if (shouldPrint) {
                cout << "Impossible\n";
            }
            return false;
        }
    }

    if (shouldPrint) {
        cout << output;
    }
    return true;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    cin >> n >> r;
    vector<vector<int>> mustDry(n);
    for (int i = 0; i < n; ++i) {
        int w, d;
        cin >> w >> d;
        mustDry[i] = {d, w, i};
    }

    sort(mustDry.begin(), mustDry.end());
    int start = 0, end = 1e9;
    while (start + 1 < end) {
        int cur = (start + end) / 2;
        if (canDo(mustDry, cur, false)) {
            end = cur;
        } else {
            start = cur;
        }
    }

    canDo(mustDry, end, true);
}