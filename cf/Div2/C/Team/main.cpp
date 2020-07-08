#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    //Mixed this up
    cin >> m >> n;
    string out="";
    while (n>m){
        out+="1";
        n--;
        if(!n){ break;}
        out+="1";
        n--;
        if(!m){ break;}
        out+="0";
        m--;
    }
    if(m>n){
        m--;
        out+="0";
    }
    while ((m||n)&& out[out.size()-1]!='1'){
        if(!n){ break;}
        out+="1";
        n--;
        if(!m){ break;}
        out+="0";
        m--;
    }

    if(m||n){
        cout << -1;
    } else{
        cout << out;
    }
}