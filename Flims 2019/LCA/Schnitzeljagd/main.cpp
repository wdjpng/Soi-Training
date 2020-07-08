#include <bits/stdc++.h>

#define int long long


using namespace std;
int n,l, timer=0;
vector<int>pre, post;
vector<int>depth;
vector<vector<int>>up;
void dfs(int v, int p, vector<vector<int>>&E, vector<vector<int>>&up){
    up[v][0]=p;
    pre[v]=++timer;
    for (int i = 1; i <= l; ++i) {
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for (int w : E[v]) {
        if(w==p){ continue;}
        depth[w]=depth[v]+1;
        dfs(w,v,E,up);
    }
    post[v]=++timer;
}


bool is_ancestor(int u, int v) {
    return pre[u] <= pre[v] && post[u] >= post[v];
}
int lca(int u, int v){
    if(is_ancestor(u,v)){
        return u;
    }
    if(is_ancestor(v,u)){
        return v;
    }
    for (int i = l; i >= 0; --i) {
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    }

    return up[u][0];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<vector<int>>E(n);
    pre.resize(n);
    post.resize(n);
    depth.resize(n);
    l=ceil(log2(n));
    up.assign(n, vector<int>(l+1));

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs(0,0,E,up);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int a,b;
        cin >> a >> b;

        cout << depth[a]+depth[b]-2*depth[lca(a,b)] << "\n";
    }
}