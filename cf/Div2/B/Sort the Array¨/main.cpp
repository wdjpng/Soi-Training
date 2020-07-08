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

    vector<int>input2=input;
    sort(input.begin(), input.end());

    int l=-1, r=0;
    for (int i = 0; i < n; ++i) {
        if(l==-1&&input[i]!=input2[i]){l=i;}
        if(input[i]!=input2[i]){r=i;}
    }
    if(l<0){l++;}
    reverse(input2.begin()+l, input2.end()-n+r+1);
    for (int i = 0; i < n; ++i) {
        if(input[i]!=input2[i]){
            cout << "no";
            exit(0);
        }
    }

    cout << "yes \n" << l+1 << " " << r+1;
}