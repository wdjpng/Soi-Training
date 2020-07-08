#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string a;
    cin >> a;

    int n = a.size();
   vector<int>oldMemory(n, 0);
   vector<int>newMemory(n, 0);

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            newMemory[j] = max({oldMemory[j], newMemory[j - 1], oldMemory[j - 1]});

            if (a[i] == a[j]) {
                newMemory[j] = max(newMemory[j], oldMemory[j-1] + 2);


            }
            if (i == j) {
                newMemory[j] = 1;
            }
        }
        oldMemory=newMemory;
    }

    cout << oldMemory[n - 1];
}

