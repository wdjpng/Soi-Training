#include <bits/stdc++.h>

#define int long long
using namespace std;

int n;

vector<int> maxVal(vector<vector<int>> &val, bool b) {
    vector<int> sum1(2*n, -1);
    vector<int> sum2(2*n,  -1);
    for (int i = -n; i < n; i ++) {
        if((i%2==0&&b)||(i%2&&!b)){ continue;}
        int j = 0;
        sum1[i+n]=0;
        while (i + j < n && j < n) {
            if (i + j < 0) {
                j++;
                continue;
            }
            sum1[i + n ] += val[i + j][j];
            j++;
        }

    }

    for (int i = 0; i < 2*n; i ++) {
        if((i%2==0&&b)||(i%2&&!b)){ continue;}
        int j = 0;
        sum2[i]=0;
        while (i - j >= 0 && j < n) {
            if (i - j >= n) {
                j++;
                continue;
            }
            sum2[i] += val[i - j][j];
            j++;
        }
    }

    int maxx = -1;
    int x, y;
    for (int i = 0; i < 2*n; ++i) {
        for (int j = 0; j < 2*n; ++j) {
            int x2=i-n;
            int y2=j;
            int newX = x2 + (y2 - x2) / 2;
            int newY = (y2 - x2) / 2;
            if(newX<0||newY<0||newX>=n||newY>=n){ continue;}
            if (maxx < sum1[i] + sum2[j] - val[newX][newY]) {
                maxx = sum1[i] + sum2[j] - val[newX][newY];
                x = newX;
                y = newY;
            }
        }
    }

    return {maxx, y + 1, x + 1};
}


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> val(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> val[j][i];
        }
    }

    vector<int> a = maxVal(val, true);
    vector<int> b = maxVal(val, false);
    cout << a[0] + b[0] << "\n" << a[1] << " " << a[2] << " " << b[1] << " " << b[2];
}