#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

// Easy O(1) solution, who needs general solutions anyways
bool isPrim(int n){
    return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int counter = 0;
    vector<int>perm(9);
    for (int i = 0; i < 9; ++i) {
        cin >> perm[i];
    }
    for (int i = 1; i < 100001; ++i) {
        perm[0]=i;
        perm[4]=perm[0]+perm[1]+perm[2]-perm[3]-perm[5];
        perm[8]=perm[0]+perm[1]+perm[2]-perm[6]-perm[7];
        int sum=perm[0]+perm[1]+perm[2];
        vector<int>sums;
        for (int j = 0; j < 3; ++j) {
            sums.push_back(perm[3*j]+perm[3*j+1]+perm[3*j+2]);
            sums.push_back(perm[j]+perm[j+3]+perm[j+6]);
        }
        sums.push_back(perm[0]+perm[4]+perm[8]);
        sums.push_back(perm[2]+perm[4]+perm[6]);
        if(sums.size() == count(sums.begin(), sums.end(), sum)){
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cout << perm[j*3+k] << " ";
                }
                cout << "\n";
            }
            break;
        }
    }
}