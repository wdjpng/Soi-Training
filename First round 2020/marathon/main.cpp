#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;
#define int long long
ifstream fin("/home/wdjpng/Downloads/marathon-sub5-attempt0.txt");
#define cin fin

signed main() {
    int testCases;
    cin >> testCases;

    freopen("output.txt","w",stdout);

    for (int i = 0; i < testCases; ++i) {
        int n, maxHoles;
        cin >> n >> maxHoles;

        vector<int> holeSum(n);

        cin >> holeSum[0];
        for (int j = 1; j < n; ++j) {
            cin >> holeSum[j];
            holeSum[j]+=holeSum[j-1];
        }

        vector<int> holeSum2 = holeSum;

        for (int k = n-1; k >0; --k) {
            holeSum[k] = holeSum[k-1];
        }
        holeSum[0] = 0;
        int lastIndexWithWorkingHoleNumber = 0;
        int maxLength = -1;
        for (int lastHole = 0; lastHole < n; ++lastHole) {
            if(lastHole < n -1){
                if(holeSum2[lastHole] == holeSum2[lastHole+1]){
                    continue;
                }
            }

            int desiredHoleSum = holeSum2[lastHole] - maxHoles;
            if(desiredHoleSum < 0){
                desiredHoleSum = 0;
            }
            int firstWorkingIndex = -1;
            for (int j = lastIndexWithWorkingHoleNumber; j < n; ++j) {
                if(holeSum[j] == desiredHoleSum){
                    firstWorkingIndex = j;
                    lastIndexWithWorkingHoleNumber = j;
                    break;
                }
            }

            if(lastHole - firstWorkingIndex + 1 > maxLength){
                maxLength = lastHole - firstWorkingIndex + 1;
            }
        }
        cout << "Case #" << i << ": " << maxLength << "\n";
    }
}