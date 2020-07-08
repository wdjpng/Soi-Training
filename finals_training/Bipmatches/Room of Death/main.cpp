#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, m;
vector<vector<int>> E;
vector<int> matching;

vector<bool> visited;

bool improveMatching(int i) {
    if (visited[i]) { return false; }
    visited[i] = true;
    if (i < n) {
        if (matching[i] == -1) { return true; }

        return improveMatching(matching[i]);
    } else{
        for (int next : E[i]) {
            if(matching[next] == i){ continue;}

            if(improveMatching(next)){
                matching[next]=i;
                return true;
            }
        }
    }

    return false;
}

vector<bool> covered(m);
bool improveMatching(){
    covered.assign(m, false);

    for(int i : matching){
        if(i != -1){
            covered[i - n] = true;
        }
    }

    visited.assign(n+m, false);
    for (int i = n; i < n+m; ++i) {
        if(!covered[i-n] && improveMatching(i)){
            return true;
        }
    }

    return false;
}

int maximumMatching() {
    matching.assign(n, -1);
    while (improveMatching()) {}
    return n - (int)count(matching.begin(), matching.end(), -1);
}

vector<int> cover;
int minimumVertexCover() {
    int size = maximumMatching();
    for (int i = 0; i < n; i++)
        if (visited[i]) cover.push_back(i);
    for (int i = n; i < n + m; i++)
        if (!visited[i]) cover.push_back(i);
    assert((int)cover.size() == size);
    return size;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int s, t, traps;
    cin >> s >> traps >> t;
    n = m = s;
    E = vector<vector<int>>(n+m);

    for (int i = 0; i < traps; ++i) {
        int x,y;
        cin >>x>>y;
        E[x].push_back(y+s);
        E[y+s].push_back(x);
    }

    cout << minimumVertexCover() << "\n";

    for (int i = 0; i < cover.size(); ++i) {
        if(cover[i] < s){cout << "V " << cover[i] << "\n";}
        else{cout << "H " << cover[i]-s << "\n";}
    }
}