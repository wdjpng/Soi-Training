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
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        s+=input[i];
    }

    if(s%3||n<3){
        cout << "0";
        exit(0);
    }

    vector<int>indexes;
    int curS = 0;
    for (int i = n-1; i >= 2; --i) {
        curS+=input[i];
        if(curS == s/3){
           indexes.push_back(i);
        }
    }
    reverse(indexes.begin(), indexes.end());
    int ways=0;
    curS=0;
    for (int i = 0; i < n-2; ++i) {
        curS+=input[i];
        if(curS==s/3){
            ways+=indexes.end() - upper_bound(indexes.begin(), indexes.end(), i+1);
        }
    }

    cout << ways;
}