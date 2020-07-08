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
    vector<int>input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    vector<int>in=input;
    sort(input.begin(), input.end());
    int shift = 0;
    for (shift = 0; shift < n; ++shift) {
        if(in[shift]<in[(shift-1+n)%n]){ break;}
    }
    shift = (n-shift)%n;
    for (int i = 0; i < n; ++i) {
        if(in[i]!=input[(i+shift)%n]){
            cout <<"-1";
            exit(0);
        }
    }
    cout << shift;
}