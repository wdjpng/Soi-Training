#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>>chef;
vector<int> find(int i){
    if(i == chef[i][0]){
        return chef[i];
    } else{
        return chef[i] = find(chef[i][0]);
    }
}

void unite(int a, int b){
    vector<int>chefA = find(a);
    vector<int> chefB = find(b);

    chefA[1]=chefB[1]=min(chefA[1], chefB[1]);
    chefA[2]=chefB[2]=max(chefA[2], chefB[2]);

    if(rand()%2){
        chefA[0]=chefB[0];
    } else{
        chefB[0]=chefA[0];
    }
}

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    chef=vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
        chef[i]={i, i, i};
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a-1, b-1);
    }

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            cout << find(x-1)[2] - find(x-1)[1];
        } else{
            int x, y;
            cin >> x >> y;
            unite(x-1, y-1);
        }
    }
}