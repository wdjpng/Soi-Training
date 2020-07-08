#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, k, d;
vector<vector<int>>mem(1000, vector<int>(1000));
int z =0;
bool busFill(vector<int>studs, int day){
    if(studs.size()==0){ return true;}
    if(day==d){ return studs.size()==1;}
    bool hasSol=true;

    int off=0;
    for (int i = 0; i < studs.size()%k; ++i) {
        if(off==studs.size()){ break;}
        vector<int>newStuds;
        for (int j = 0; j < studs.size()/k+1; ++j) {
            newStuds.push_back(studs[off]);
            mem[day][studs[off]]=i+1;
            off++;
        }
        hasSol&=busFill(newStuds, day+1);
    }

    for (int i = 0; i < k-studs.size()%k; ++i) {
        if(off==studs.size()){ break;}
        vector<int>newStuds;
        for (int j = 0; j < studs.size()/k; ++j) {
            mem[day][studs[off]]=i+1+studs.size()%k;
            newStuds.push_back(studs[off]);
            off++;
        }
        hasSol&=busFill(newStuds, day+1);
    }

    return hasSol;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    cin >> n >> k >> d;
    k=min(k, n);
    vector<int>studs;
    for (int i = 0; i < n; ++i) {
        studs.push_back(i);
    }
    if(!busFill(studs,0)){cout << -1;} else{
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << mem[i][j] << " ";
            }
            cout << "\n";
        }
    }
}