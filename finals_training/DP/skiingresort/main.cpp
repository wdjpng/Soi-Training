#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

const int INF = 1e16;

// Finally found that edge case
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> k >> m;

    vector<vector<pair<int, int>>> lifts(n);
    vector<vector<pair<int, int>>> pists(n);
    for (int i = 0; i < k; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        lifts[max(a, b)].push_back(make_pair(min(a, b), d));
    }
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        pists[min(a, b)].push_back(make_pair(max(a, b), d));
    }


    vector<vector<int>> pistDist(n, vector<int>(n, -INF));
    vector<vector<int>> liftDist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        liftDist[i][i]=0;
        for (int j = i+1; j < n; ++j) {
            for (pair<int, int> next : lifts[j]){
                liftDist[i][j]=min(liftDist[i][j], liftDist[i][next.first] + next.second);
            }
        }

        pistDist[i][i]=0;
        for (int j = i-1; j >= 0; --j) {
            for (pair<int, int> next : pists[j]){
                pistDist[i][j]=max(pistDist[i][j], pistDist[i][next.first] + next.second);
            }
        }
    }

    double max = -1;
    int sOpt, eOpt;
    for (int start = 1; start < n; ++start) {
        for (int end = 0; end < start; ++end) {
            if(liftDist[end][start] > INF/10 || pistDist[start][end] < -INF/10){ continue;}
            double cur = ((double) pistDist[start][end])/((double) liftDist[end][start]);

            if(cur > max){
                max=cur;
                sOpt = start;
                eOpt = end;
            }
        }
    }

    if (max == -1) {
        cout << "None";
    } else {
        cout << sOpt << " " << eOpt << " " << liftDist[eOpt][sOpt] << " " << pistDist[sOpt][eOpt];
    }
}