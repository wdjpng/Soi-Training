#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>>in;
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        in.push_back({s,1,i});
        in.push_back({s,0,i});
    }
    sort(in.begin(), in.end());

    vector<int>dojoPos(n);
    set<int>dojo;
    set<pair<int, int>>dists;
    dists.insert(make_pair(-m+1, 0));
    for (int i = 0; i < 2*n; ++i) {
        if(in[i][2]==0){
            auto it = dojo.lower_bound(dojoPos[in[i][3]]);
            auto it2 = it;
            it2++;

            int start = 0, length = m;
            if(it!=dojo.begin()){it--;start=*it+1;}

            if(it2!=dojo.end()){length=start-*it2;}

            //Find dist starting from cur + 1
            auto it3 = dists.lower_bound(make_pair(dojoPos[in[i][3]]+1, 0));
            dists.erase(it3);

            dojo.erase(dojoPos[in[i][3]]);
        } else{
            int cur = in[i][2];
            int offset =-(*dists.begin()).first, start = (*dists.begin()).second;

            dojoPos[cur]=start + offset/2;
            dojo.insert(dojoPos[cur]);

            dists.erase(dists.begin());
            dists.insert(make_pair(-start, offset/2-1));
            dists.insert(make_pair(-offset/2-1, offset-dojoPos[cur]));
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dojoPos[i] << "\n";
    }
}
