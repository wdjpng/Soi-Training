#include <bits/stdc++.h>

#define int long long

using namespace std;
vector<int> mem;
vector<int>depth;
vector<int>pre;
vector<int>lastElement;
int n,q;
int times = 0;

int get(int x) {
    if(x<1){return 0;}
    int r = 0;
    for (int i = x; i > 0; i -= i & -i)
        r += mem[i];

    return r;
}

// increment range l to r
void incrementRange(int l, int r, int increment) {
    int orgInc=increment;

    for (int i = l+1; i <= n+1; i += i & -i)
        mem[i]+=increment;

    for (int i = r+2; i <= n+1; i += i & -i)
        mem[i]-=increment;
}

void dfs(int v, int p, vector<vector<pair<int, int>>>&E){
    pre[v]=++times;
    for (auto w : E[v]) {
        if(w.first==p){ continue;}
        depth[w.first]=depth[v]+w.second;
        dfs(w.first,v,E);
    }
    lastElement[v]=times;
}


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n >> q;
    mem=vector<int>(n+2



            );
    pre=vector<int>(n);
    depth=vector<int>(n);
    lastElement=vector<int>(n);
    vector<vector<pair<int, int>>>E(n);

    for (int i = 1; i < n; ++i) {
        int v, c;
        cin >> v >> c;
        E[v].push_back(make_pair(i,c));
    }
    dfs(0,-1,E);
    for (int i = 0; i < n; ++i) {
        incrementRange(pre[i], lastElement[i], depth[i]);
    }
    for (int i = 0; i < q; ++i) {
        char a;
        int l;
        cin >> a >> l;
        if(a=='q'){
            l=pre[l];
            cout << get(l+1) - get(l) << "\n";
            continue;
        }

        int c;
        cin >> c;
        int diff=c-depth[l];
        depth[l]=c;

        incrementRange(pre[l], lastElement[l], diff);
    }
}