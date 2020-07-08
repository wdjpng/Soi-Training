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
    n = 0, m = 0;


    vector<vector<bool>> isBlocked(r, vector<bool>(c, false));
    vector<vector<int>> val(r, vector<int>(c, -1));
    for (int i = 0; i < r; ++i) {
        string x;
        cin >> x;
        for (int j = 0; j < c; ++j) {
            if (x[j] == 'X') {
                isBlocked[i][j] = true;
            } else if (x[j] == '.') {
                val[i][j] = n;
                n++;
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (val[i][j] == -1 && !isBlocked[i][j]) {
                val[i][j] = n + m;
                m++;
            }
        }
    }

    E = vector<vector<int>>(n + m);
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (isBlocked[j][i]) { continue; }
            for (int x = i - 2; x <= i + 2; ++x) {
                for (int y = j - 2; y <= y + 2; ++y) {
                    if (y >= r || x >= c) break;
                    if (abs(x - i) + abs(y - j) != 3 ) { continue; }
                    if (y < 0 || x < 0 || i == x || j == y || isBlocked[y][x]) { continue; }

                    E[val[j][i]].push_back(val[y][x]);
                }
            }
        }
    }

    int matchings = n + m - maxMatching();

    cout << matchings << "\n";

    if(b){exit(0);}
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (isBlocked[i][j]) {
                cout << "X";
            } else if ((val[i][j] < n && !visited[val[i][j]]) || (val[i][j] >= n && visited[val[i][j]])) {
                cout << "♘";
            } else if (val[i][j] < n) {
                cout << ".";
            } else {
                cout << "#";
            }
        }
        cout << "\n";
    }

}