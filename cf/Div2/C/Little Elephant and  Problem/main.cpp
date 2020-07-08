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

    vector<int>in(n);
    vector<int>in2(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        in2[i]=in[i];
    }
    sort(in.begin(), in.end());

    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum+=in[i]!=in2[i];
    }

    if(sum<3){cout << "YES";} else{
        cout << "NO";
    }
}