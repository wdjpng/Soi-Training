#include <bits/stdc++.h>

#define int long long
using namespace std;


int m;
string a;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);



    cin >> a >> m;

    //First difference, then curM, then lastAd
    stack<vector<int>>q;
    q.push({0,0,0});
    map<vector<int>, vector<int>>mem;
    while (q.size()){
        vector<int>cur=q.top();
        q.pop();

        if(cur[1]==m){ break;}
        for (int i = 1; i <= a.size(); ++i) {
            if(a[i-1]=='0'){ continue;}

            vector<int>next={i-cur[0], cur[1]+1, i};
            if(i<=cur[0]||i==cur[2]||mem.find(next)!=mem.end()){ continue;}

            q.push(next);
            mem[next]=cur;
        }
    }

    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= a.size(); ++j) {
            if(mem.find({i, m, j})==mem.end()){ continue;}
            cout << "YES\n";
            vector<int>cur={i, m, j};
            vector<int>out;
            for (int i = 0; i < m; ++i) {
                out.push_back(cur[2]);
                cur=mem[cur];
            }
            reverse(out.begin(), out.end());
            for (int i = 0; i < m; ++i) {
                cout << out[i] << " ";
            }
            exit(0);
        }
    }

    cout << "NO";
}