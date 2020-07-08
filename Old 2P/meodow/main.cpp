#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int maxFields, n, maxFieldWidth;
    cin >> n >> maxFields >> maxFieldWidth;

    vector<int> heights(n);
    vector<vector<int>> DP(n, vector<int>(maxFields+1, 0));

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    for (int k = 1; k <= maxFields; ++k) {
        for (int i = 0; i < n; ++i) {
            int min = heights[i];
            int max = i ? DP[i-1][k]:0;
            for (int w =1; w <= maxFieldWidth && i-w>=0; ++w) {
                if (heights[i-w+1] < min) {
                    min = heights[i-w+1];
                }

                int cur = w * min + DP[i-w][k-1];
                if (cur > max) {
                    max = cur;
                }
            }
            DP[i][k] = max;
        }
    }

    cout <<DP[n-1][maxFields];
}