#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    // The following line disables syncing between cin/scanf and cout/printf.
    // It makes input faster, but you must not use functions from <cstdio> (e.g. scanf/printf) directly.
    // This line must be executed before any use of cin/cout.
    ios_base::sync_with_stdio(false);

   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<pair<int, int>>>E(n);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a-1].push_back(make_pair(b-1, c));
        E[b-1].push_back(make_pair(a-1, c));
    }

    vector<int>special(k);
    vector<bool>isSpecial(n, false);
    for (int i = 0; i < k; ++i) {
        cin >> special[i];
        special[i]--;
        isSpecial[special[i]]=true;
    }

    vector<int>vis(n, 1e18);
    priority_queue<vector<int>>pq;
    for (int i = 0; i < k; ++i) {
        vis[special[i]]=0;
        pq.push({0, special[i], special[i]});
    }

    vector<int>opt = {static_cast<long long>(1e10), -1, -1};
    vector<int>opt2 = {static_cast<long long>(1e10), -1, -1};
    while (pq.size()){

        int cur = pq.top()[1];
        int lastDepth = -pq.top()[0];
        int father=pq.top()[2];
        pq.pop();

         for (pair<int, int> next : E[cur]) {
            if(isSpecial[next.first]&&next.second+lastDepth<opt[0]&&next.first!=father){
                if(next.first!=opt[1] && father!=opt[1] &&next.first!=opt[2] && father!=opt[2]){
                    opt2=opt;
                }
                opt={next.second+lastDepth, father, next.first};
            } else if(isSpecial[next.first]&&next.second+lastDepth<opt2[0]&&next.first!=father&&next.first!=opt[1] && father!=opt[1] &&next.first!=opt[2] && father!=opt[2]){
                opt2={next.second+lastDepth, father, next.first};
            }
            if(vis[next.first] <= lastDepth+next.second){ continue;}
            vis[next.first]=lastDepth+next.second;
            pq.push({-lastDepth-next.second, next.first, father});
        }
    }
    int curTime = opt[0]+opt2[0];


    pq.push({0, opt[1]});
    vector<int>depth(n, 1e18);
    for (int i = 0; i < k; ++i) {
        depth[special[i]]=0;
    }

    int minDist1=1e18;
    int sec;
    while (pq.size()){
        int cur = pq.top()[1];
        int lastDepth = -pq.top()[0];

        pq.pop();

        for (pair<int, int> next : E[cur]) {
            if(next.first==opt[1]||next.first==opt[2]){ continue;}
            if(isSpecial[next.first]&&minDist1>lastDepth+next.second){
                minDist1=lastDepth+next.second;
                sec=next.first;
            }
            if(depth[next.first] <= lastDepth+next.second){ continue;}
            depth[next.first]=lastDepth+next.second;
            pq.push({-lastDepth-next.second, cur});
        }
    }


    pq.push({0, opt[2]});
   depth.assign(n, 1e18);
    for (int i = 0; i < k; ++i) {
        depth[special[i]]=0;
    }
    pq.push({0, opt[2]});
    int minDist2=1e10;
    while (pq.size()){
        int cur = pq.top()[1];
        int lastDepth = -pq.top()[0];

        pq.pop();

        for (pair<int, int> next : E[cur]) {
            if(next.first==opt[1]||next.first==opt[2]||next.first==sec){ continue;}
            if(isSpecial[next.first]&&minDist2>lastDepth+next.second){
                minDist2=lastDepth+next.second;
            }
            if(depth[next.first] <= lastDepth + next.second){ continue;}
            depth[next.first]=lastDepth + next.second;
            pq.push({-lastDepth-next.second, cur});
        }
    }

    cout << min(minDist1+minDist2, curTime);
}
