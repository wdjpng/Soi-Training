#include<soi>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < n; ++i) 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int INF = 1e11;
    int n;
    cin >> n;
    vector<vector<int>>dist(n, vector<int>(n, INF));
    vector<vector<int>>G(n, vector<int>(n));
    rep(i, n){
        dist[i][i]=0;
        rep(j, n){
            cin >> i >> j;
        }
    }
    
    int sum = 0;
    vector<int>out;
    vector<int>in(n);
    rep(i,n){cin >> in[i];}
    vector<bool>disc(n);
    reverse(in.begin(), in.end());

    for(int i : in){
        i--;

        rep(j,n){
            rep(k,n){
                if(disc[j]||disc[k])continue;
                if(dist[j][k]>G[j][i]+G[i][k]){
                    sum-=dist[j][k]-G[j][i]-G[i][k];
                    dist[j][k]=G[j][i]-G[i][k];
                }
                dist[i][j]=min(dist[j][k]+dist[k][i], dist[i][j]);
            }
        }

        rep(j, n){
            sum+=dist[i][j];
        }
        out.push_back(sum);
        disc[i]=true;
    }

    reverse(out.begin(), out.end());
    rep(i,n){
        cout << out[i];
    }
}
