#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<vector<int>> E;
vector<pair<int, int>>memory;


pair<int, int> maxIndepenentSet(int cur) {
    if(memory[cur].first != -1){
        return memory[cur];
    }

    //Pending
    memory[cur].first=-2;

    int sumTakeCur = 1;
    int sumDontTakeCur = 0;

    for (int next : E[cur]) {
        if(memory[next].first==-2){ continue;}
        sumTakeCur+=maxIndepenentSet(next).second;
        sumDontTakeCur+=maxIndepenentSet(next).first;
    }

    return memory[cur] = make_pair(max(sumTakeCur, sumDontTakeCur), sumDontTakeCur);
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    E = vector<vector<int>>(n);
    memory = vector<pair<int, int>>(n, make_pair(-1, -1));
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    cout << max(maxIndepenentSet(0).first, maxIndepenentSet(0).second);
}