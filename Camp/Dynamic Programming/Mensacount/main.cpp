#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, goal;
    cin >> n >> goal;
    vector<int> input(n);

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        if (input[i] > goal) {
            i--;
            n--;
        }
    }


    vector<int> oldMemory(goal + 1);
    vector<int> newMemory(goal + 1);
    oldMemory[0] = 1;
    oldMemory[input[0]] = 1;

    for (int i = 1; i < n; ++i) {
        for (int curSum = 0; curSum <= goal; ++curSum) {
            if (oldMemory[curSum]) {
                newMemory[curSum] += oldMemory[curSum];

                if (curSum + input[i] <= goal) {
                    newMemory[curSum + input[i]] += oldMemory[curSum];
                }
            }
        }
        oldMemory = newMemory;
        newMemory = vector<int>(goal+1);
    }

    cout << oldMemory[goal] << "\n";
}