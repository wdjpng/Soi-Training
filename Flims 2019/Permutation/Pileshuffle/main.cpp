#include <bits/stdc++.h>

#define int long long


using namespace std;

int length=0;
int cycle(int v, vector<bool>&visited, vector<int>&E){
    if(visited[v]){return length;}
    visited[v]=true;
    length++;
    return cycle(E[v], visited,E);
}
signed main() {
    int n,p;
    cin >> n >> p;

    vector<vector<int>>pile(p);
    for (int i = 0; i < n; ++i) {
        pile[i%p].push_back(i);
    }
    for (int i = 0; i < p; ++i) {
       reverse(pile[i].begin(), pile[i].end());
    }

    pair<int, vector<int>> minn = make_pair(1e18,vector<int>(2));
    for(int k =0; k < 40321; k++) {
       length=0;
       int lcms=1;
        vector<bool>visited(n);
        vector<int>E(n);
        int c=0;
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < pile[i].size(); ++j) {
                E[pile[i][j]]=c++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(visited[i]){ continue;}
            length=0;
            int gcd=__gcd(lcms, cycle(i, visited, E));
            lcms=(lcms/gcd)*(cycle(i, visited, E));
        }
        vector<int>piles;
        for (int i = 0; i <pile.size(); ++i) {
            piles.push_back(pile[i][pile[i].size()-1]);
        }
        minn=min(minn, make_pair(lcms, piles));
        next_permutation(pile.begin(), pile.end());
    }
    cout << minn.first << "\n";
    for (int i = 0; i < p; ++i) {
        cout << minn.second[i] << " ";
    }
}