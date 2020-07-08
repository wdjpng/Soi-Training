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
    for (int i = 0; i < t; ++i) {
        int n, c;
        cin >> n >> c;

        vector<int>stalls(n);
        for (int j = 0; j < n; ++j) {
            cin >> stalls[j];
        }
        sort(stalls.begin(), stalls.end());

        int start = 0, end = 1e13;
        while (end - start > 1){
            int cur = (start+end)/2;
            int lastIndex = 0, cowCounter = 1;
            for (int i = 1; i < n; ++i) {
                if(stalls[i] - stalls[lastIndex] >= cur){
                    cowCounter++;
                    lastIndex=i;
                }
            }

            if(cowCounter<c){
                end=cur;
            } else{
                start=cur;
            }
        }

        cout << start << "\n";
    }
}