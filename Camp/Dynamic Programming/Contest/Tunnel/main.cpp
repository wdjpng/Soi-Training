#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int rows, columns, maxStrokes;
    cin >> rows >> columns >> maxStrokes;

    int maxVal = numeric_limits<int>::max();
    vector<string> field(rows);
    vector<int> reachableNew(columns, maxVal);
    vector<int> reachableOld(columns, maxVal);

    for (int i = 0; i < rows; ++i) {
        cin >> field[i];
    }

    for (int i = 0; i < columns; ++i) {
        if (field[0][i] == 'v') {
            for (int j = i; j - i <= maxStrokes && j < columns; ++j) {
                if (field[0][j] == '#')break;
                reachableOld[j] = j - i;
            }
            for (int moveLeft = 1; i - moveLeft >= 0 && moveLeft <= maxStrokes; ++moveLeft) {
                if (field[0][i - moveLeft] == '#')break;
                reachableOld[i - moveLeft] = moveLeft;
            }

            break;
        }
    }

    for (int i = 1; i < rows; ++i) {
        queue<pair<int, int>> queue;//Cur index, actions left
        for (int j = 0; j < reachableOld.size(); ++j) {
            if (reachableOld[j] != maxVal) {
                if (field[i][j] == '.') {
                    reachableNew[j] = reachableOld[j];
                    queue.push(make_pair(j, maxStrokes));
                }
            }
        }

        while (queue.size()) {
            int curIndex = queue.front().first;
            int actionsLeft = queue.front().second;
            queue.pop();

            if (actionsLeft == 0) {
                continue;
            }

            for (int move = max((int) 0, curIndex - 1); move < min(columns, curIndex + 2); ++move) {
                if (reachableNew[move] > reachableNew[curIndex] + 1 && field[i][move] == '.') {
                    reachableNew[move] = reachableNew[curIndex] + 1;
                    queue.push(make_pair(move, actionsLeft - 1));
                }
            }
        }

        reachableOld = reachableNew;
        reachableNew = vector<int>(columns, maxVal);
    }

    int minimum = maxVal;
    for (int i = 0; i < columns; ++i) {
        minimum = min(minimum, reachableOld[i]);
    }

    if (minimum == maxVal) {
        cout << "-1\n";
    } else {
        cout << minimum << "\n";
    }
}