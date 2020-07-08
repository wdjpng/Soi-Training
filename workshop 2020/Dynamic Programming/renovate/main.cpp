#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

int renovation(int cur, vector<int> &memory, vector<int> &bottlesArray) {
    if(memory[cur] != -1){
        return memory[cur];
    }
    if(cur >= bottlesArray.size()){
        return 0;
    }

    int maximum = bottlesArray[cur];
    if(cur + 1 < bottlesArray.size()){
        maximum = max(maximum, renovation(cur + 1, memory, bottlesArray));
    }
    if(cur + 2 < bottlesArray.size()){
        maximum = max(maximum, bottlesArray[cur] + renovation(cur + 2, memory, bottlesArray));
    }

    return memory[cur] =  maximum;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n, m;
    cin >> m>>n;
    vector<int> memory(n, -1);
    vector<int> bottleArray(n, 0);
    for (int i = 0; i < m; ++i) {
        int counter = 0;
        for (int j = 0; j < n; ++j) {
            int plus;
            cin >> plus;
            if(plus == 0){
                counter++;
                bottleArray[j]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        bottleArray[0] = 0;
        bottleArray[n-1] = 0;
    }

    cout << renovation(0, memory, bottleArray);
}