#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    int curPos = 0;
    int sum=0;
    vector<int>input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    for (int i = 0; i < n; ++i) {
        int cur = input[i];
        sum+=cur-curPos+1;
        curPos=cur;
        if(i<n-1){
            sum++;
            if(input[i+1]<cur){
                sum+=cur-input[i+1];
                curPos=input[i+1];
            }
        }
    }

    cout << sum;
}