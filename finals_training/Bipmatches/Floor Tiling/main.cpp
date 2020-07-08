#include <bits/stdc++.h>

#define int long long
using namespace std;

int n = 0, m = 0;
vector<vector<int>> E;
vector<int> matching;

vector<bool> visited;

bool improveMatching(int i) {
    if (visited[i]) { return false; }
    visited[i] = true;
    if (i < n) {
        if (matching[i] == -1) { return true; }

        return improveMatching(matching[i]);
    } else {
        for (int next : E[i]) {
            if (matching[next] == i) { continue; }

            if (improveMatching(next)) {
                matching[next] = i;
                return true;
            }
        }
    }

    return false;
}

vector<bool> covered(m);

bool improveMatching() {
    covered.assign(m, false);

    for (int i : matching) {
        if (i != -1) {
            covered[i - n] = true;
        }
    }

    visited.assign(n + m, false);
    for (int i = n; i < n + m; ++i) {
        if (!covered[i - n] && improveMatching(i)) {
            return true;
        }
    }

    return false;
}

int maxMatching() {
    matching.assign(n, -1);
    while (improveMatching()) {}

    // I love this function
    return n - count(matching.begin(), matching.end(), -1);
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int r, c, b;
    cin >> r >> c >> b;

    vector<vector<int>> val(r, vector<int>(c, -1));
    bool flag1 = false;
    for (int i = 0; i < r; ++i) {
        bool flag2 = flag1;
        flag1 = !flag1;
        for (int j = 0; j < c; ++j) {
            flag2 = !flag2;
            if (flag2) {
                val[i][j] = n;
                n++;
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (val[i][j] == -1) {
                val[i][j] = n + m;
                m++;
            }
        }
    }

    E = vector<vector<int>>(r * c);

    vector<vector<bool>> isBlocked(r, vector<bool>(c, false));
    for (int i = 0; i < b; ++i) {
        int x, y;
        cin >> y >> x;

        isBlocked[y][x] = true;
    }

    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (isBlocked[j][i]) { continue; }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= y + 1; ++y) {
                    if (y == r || x == c) break;
                    if (abs(x - i) + abs(y - j) > 1) { continue; }
                    if (y < 0 || x < 0 || (i == x && j == y) || isBlocked[y][x]) { continue; }

                    E[val[j][i]].push_back(val[y][x]);
                }
            }
        }
    }

    int matchings = maxMatching();
    if (r * c - b == 2 * matchings) {
        cout << "Yes";
        cout << "\n";

        bool debugMode = false;
        if (!debugMode) { exit(1); }

        vector<vector<char>> out(r, vector<char>(c, ' '));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (val[i][j] < n) {
                    if(abs(matching[val[i][j]]-val[i][j]-n) == 1){
                        out[i][j]='-';
                        if(matching[val[i][j]]-val[i][j]-n >= 0){
                            out[i][j-1]='-';
                        } else{
                            out[i][j+1]='-';
                        }
                    } else{
                        out[i][j]='|';
                        if(matching[val[i][j]]-val[i][j]-n >= 0){
                            out[i-1][j]='|';
                        } else{
                            out[i+1][j]='|';
                        }
                    }
                }
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << out[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "No " << r * c - b - 2 * matchings;
    }
}