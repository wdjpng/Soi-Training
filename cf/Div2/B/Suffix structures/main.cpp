#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    int bP=0;
    bool sau = false;
    for(int i=0,j=0; i<a.size(); ++i){
        if(j<b.size() && a[i]==b[j]) ++j;
        if(j==b.size()) sau = true;
    }

    bool array=true, both=true;
    vector<int>c(30);
    for (int i = 0; i < a.size(); ++i) {c[a[i]-'a']++;}
    for (int i = 0; i < b.size(); ++i) {c[b[i]-'a']--;}
    for (int i = 0; i < c.size(); ++i) {
        if(c[i]!=0){array=false;}
        if(c[i]<0){both=false;}
    }

    //Please kill me
    if(sau) cout << "automaton\n"; else
    if(array){
        cout << "array\n";
    } else if (both){
        cout << "both\n";
    } else{
        cout << "need tree\n";
    }
}