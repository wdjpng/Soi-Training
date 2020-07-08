#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    string a, b;
    cin >> a;
    vector<int> m(30);
    for (int i = 0; i < a.size(); ++i) m[a[i]-'a']++;
    int c=0;
    for (int i = 0; i < 30; ++i) {
        c+=m[i]%2;
    }

    if(c<2||c%2){
        cout << "First";
    } else{
        cout << "Second";
    }

}