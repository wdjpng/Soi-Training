#include <bits/stdc++.h>

#define int long long
using namespace std;

bool smaller(pair<int, int>lhs, pair<int, int>rhs){
    return abs(lhs.first)<abs(rhs.first)||(abs(lhs.first)==abs(rhs.first)&&abs(lhs.second)<abs(rhs.second));
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>>bombs(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        bombs[i]=make_pair(x,y);
    }
    sort(bombs.begin(), bombs.end(), smaller);

    vector<string>out;
    for (auto bomb : bombs) {
        if(bomb.second<0){
            out.push_back("1 " + to_string(-bomb.second)+ " D");
        } else if(bomb.second>0){
            out.push_back("1 " + to_string(bomb.second) + " U");
        }
        
        if(bomb.first<0){
            out.push_back("1 " + to_string(-bomb.first) + " L");
        } else if(bomb.first>0){
            out.push_back("1 " + to_string(bomb.first) + " R");
        }

        out.push_back("2");

        if(bomb.second<0){
            out.push_back("1 " + to_string(-bomb.second) + " U");
        } else if(bomb.second>0){
            out.push_back("1 " + to_string(bomb.second)+ " D");
        }
        
        if(bomb.first<0){
            out.push_back("1 " + to_string(-bomb.first) + " R");
        } else if(bomb.first>0){
            out.push_back("1 " + to_string(bomb.first)+ " L");
        }

        out.push_back("3");
    }

    cout << out.size() << "\n";
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << "\n";
    }
}