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

    vector<pair<char, int>>b;
    int c=1;
    for (int i = 1; i < a.size(); ++i) {
        if(a[i]!=a[i-1]){
            b.push_back(make_pair(a[i-1], c));
            c=1;
        } else{
            c++;
        }
    }
    b.push_back(make_pair(a[a.size()-1], c));
    b[0].second=min((int)2, b[0].second);
    for (int i = 0; i < b[0].second; ++i) {
        cout << b[0].first;
    }
    for (int i = 1; i < b.size(); ++i) {
        b[i].second=min((int)2, b[i].second);
        if(b[i].second>1&&b[i-1].second>1){
            b[i].second=1;
        }
        for (int j = 0; j < b[i].second; ++j) {
            cout << b[i].first;
        }
    }

}