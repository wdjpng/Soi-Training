#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 982451653;
const int P = 1e9+7;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string str;
    cin >> str;
    int a = 0, b=0, n=str.size();
    int curP=1;

    vector<pair<int, int>>w;
    for (int i = 0; i < n-1; ++i) {
        a+=curP*str[i];
        curP*=P;
        curP%=MOD;
        a%=MOD;
        b=b*P+str[n-1-i];
        b%=MOD;

        if(a==b){
            w.push_back(make_pair(i+1,0));
        }
    }

    int start=-1, end=w.size();
    string newStr = str.substr(1,n-2);
    for (int i = 0; i < 25; ++i) {
        int cur = (start+end)/2;
        if(cur>=w.size()){ end=cur; continue;}
        auto a = newStr.find(str.substr(0, w[cur].first));
        if(a>=newStr.size()){
            end=cur;
        } else{
            start=cur;
        }
    }

    if (start == -1) {
        cout << "Just a legend";
    } else {
        cout << str.substr(0, w[start].first);
    }
}