#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int a, b;
    string key;
    cin >> key >> a >> b;
    int pow=1;
    int n = key.size();
    int curB=0;
    vector<bool>works(n);
    for (int i = n-1; i > 0; --i) {
        curB+=pow*(key[i]-'0');
        curB%=b;
        works[i]=curB==0&&key[i]!='0';
        pow*=10;
        pow%=b;
    }
    int curA=0;
    for (int i = 0; i < n-1; ++i) {
        curA*=10;
        curA+=key[i]-'0';
        curA%=a;
        if(curA==0&&works[i+1]){
            cout << "YES\n" << key.substr(0, i+1) << "\n"<< key.substr(i+1, key.size()-i-1);
            exit(0);    
        }
    }

    cout << "NO";
}