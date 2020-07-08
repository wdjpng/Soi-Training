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

    for (int i = 0; i < a.size(); ++i) {
        if(a[i]>'1') {
            for (int j = i; j < a.size(); ++j) {
                a[j]='1';
            }
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        sum+=pow(2, a.size()-1-i)*(a[i]-'0');
    }

    cout << sum;
}