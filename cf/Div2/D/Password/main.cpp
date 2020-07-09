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
    for (int i = 0; i < n-2; ++i) {
        a+=curP*str[i];
        curP*=P;
        curP%=MOD;
        a%=MOD;
        b=b*P+str[n-1-i];
        b%=MOD;

        if(a==b){
            w.push_back(make_pair(i+1,b));
        }
    }

    int start=-1, end=w.size();

    for (int i = 0; i < 25; ++i) {
        int cur = (start+end)/2;
        if(cur>=w.size()){ end=cur; continue;}
        int hash=0;
        int pow=1;
        int j;
        for (j = n-1-w[cur].first; j < n-1; ++j) {
            hash+=(str[j]*pow)%MOD;
            hash%=MOD;
            if(j==n-2){ break;}
            pow*=P;
            pow%=MOD;
        }
        if(hash==w[cur].second){
            start=cur;
            continue;
        }
        for (j = n-2-w[cur].first; j > 0; j--) {
            hash=(hash+MOD*str[j+w[cur].first]-pow*str[j+w[cur].first])%MOD;
            hash=(hash*P+str[j])%MOD;
            if(hash==w[cur].second){
                start=cur;
                break;
            }
        }
        if(start==cur){ continue;}
        end=cur;
    }

    if (start == -1) {
        cout << "Just a legend";
    } else {
        cout << str.substr(0, w[start].first);
    }
}