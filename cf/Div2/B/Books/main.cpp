#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int>in(n);
    for (int i = 0; i < n; ++i) {
        cin>>in[i];
    }

    for (int i = 1; i < n; ++i) {
        in[i]+=in[i-1];
    }
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        int start = -1, end = n-1;
        int minus=0;
        if(i!=0){
            minus=in[i-1];
        }
        while (end-start>1){
            int cur = (start+end)/2;
            if(in[cur]-minus<=t){
                start=cur;
            } else{
                end=cur;
            }
        }
        if(start+1<n&&in[start+1]-minus<=t){
            start++;
        }
        if(start+1<n&&in[start+1]-minus<=t){
            start++;
        }
        maxx=max(maxx, start-i+1);
    }

    cout << maxx;
}