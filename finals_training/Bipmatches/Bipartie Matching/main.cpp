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

int maxMatching(){
    matching.assign(n, -1);
    while (improveMatching()){}

    // I love this function
    return n - count(matching.begin(), matching.end(), -1);
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int e, t;
    cin >> n >> m >> e >> t;

    E = vector<vector<int>>(n+m);

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;

        E[a].push_back(b);
        E[b].push_back(a);
    }

    cout << maxMatching() << "\n";

    for (int i = 0; i < n&&t; ++i) {
        if(matching[i] == -1) continue;

        cout << i << " " << matching[i] << "\n";
    }
}