#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>>points;
    vector<vector<int>>E(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < i; ++j) {
            if(points[j].first==x||points[j].second==y){
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
        points.push_back(make_pair(x,y));
    }


    int count = 0;
    vector<bool>visited(n);
    for (int i = 0; i < n; ++i) {
        if(visited[i]){ continue;}
        count++;
        visited[i]=true;
        stack<int>s;
        s.push(i);

        while (s.size()){
            int cur = s.top();
            s.pop();

            for (int next : E[cur]) {
                if(visited[next]){ continue;}
                visited[next]=true;
                s.push(next);
            }
        }
    }

    cout << count-1;
}