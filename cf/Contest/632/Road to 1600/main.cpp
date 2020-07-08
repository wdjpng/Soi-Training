#include <bits/stdc++.h>

#define int long long

using namespace std;

// No points
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n;
    cin >> n;
    if(n<3){
        cout << "-1";
        exit(0);
    }

    vector<vector<int>>out(n, vector<int>(n));
    out[0][0]=6;
    out[0][1]=5;
    out[0][2]=4;
    out[1][0]=7;
    out[1][1]=1;
    out[1][2]=3;
    out[2][0]=2;
    out[2][1]=9;
    out[2][2]=8;

    int counter = 10;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i<3&&j<3){ continue;}
            out[i][j]=counter;
            counter++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << out[i][j] << " ";
        }

        cout << "\n";
    }
}
