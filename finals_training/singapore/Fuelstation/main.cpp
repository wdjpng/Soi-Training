#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
    // The following line disables syncing between cin/scanf and cout/printf.
    // It makes input faster, but you must not use functions from <cstdio> (e.g. scanf/printf) directly.
    // This line must be executed before any use of cin/cout.
    ios_base::sync_with_stdio(false);

    // Your code goes here ...
    // (You can now read input and write output normally using cin/cout.)
    int n, d;
    cin >> n >> d;
    vector<vector<int>>in(n);
    vector<int>maxFs(n);
    for (int i = 0; i < n; ++i) {
        int a, maxF, dist;
        cin >> dist >> a >> maxF;
        in[i]={dist, a, maxF};
        maxFs[i]=maxF;
    }
    n++;
    in.push_back({d,0,0});
    sort(in.begin(), in.end());

    sort(maxFs.begin(), maxFs.end());
    int minn=d;
    for (int i = 0; i < n-1; ++i) {
        int cur = maxFs[i];
        int curF=cur;
        int last = 0;
        int minNearDeath=1e8;
        for (int i = 0; i < n; ++i) {
            curF-=in[i][0] - last;
            last=in[i][0];
            minNearDeath=min(minNearDeath, curF);
            if(cur<=in[i][2]){
                curF+=in[i][1];
            }
        }

        if(minNearDeath<0){ continue;}
        minn=min(minn, cur-minNearDeath);
    }

    cout << minn;
}
