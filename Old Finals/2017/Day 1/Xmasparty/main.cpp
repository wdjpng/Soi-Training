#include <bits/stdc++.h>

#define int long long


using namespace std;
vector<vector<int>>E;
vector<vector<int>>mem;
vector<int>h;
int n;
int maxx(int pa, int v, int p){
    if(E[v].size()==1&&pa&&v!=0){return -h[v];}
    if(E[v].size()==1&&pa==0&&v!=0){return h[v];}
    if(mem[v][pa]!=-1){return mem[v][pa];}

    int select=h[v];
    if(pa){select=-select;}
    for (int w: E[v]) {
        if(w==p){ continue;}
        select+=maxx(1, w, v);
    }

    int nS=0;
    for (int w: E[v]) {
        if(w==p){ continue;}
        nS+=maxx(0, w, v);
    }

    if(pa){
        return mem[v][pa]=max(select-h[v] , nS);
    }
    return mem[v][pa]=max(select+h[v] , nS);
}
signed main() {
    cin >> n;
    h=vector<int>(n);
    E=vector<vector<int>>(n);
    mem=vector<vector<int>>(n, vector<int>(2, -1));
    cin >> h[0];
    for (int i = 1; i < n; ++i) {
        int b;
        cin >> h[i] >> b;
        E[i].push_back(b);
        E[b].push_back(i);
    }

    cout << maxx(true,0,-1);
}