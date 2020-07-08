#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

int bottles(int cur, vector<int> &memory, vector<int> &bottlesArray) {
    if(memory[cur] != -1){
        return memory[cur];
    }
    if(cur >= bottlesArray.size()){
        return 0;
    }

    int maximum = bottlesArray[cur];
    if(cur + 1 < bottlesArray.size()){
        maximum = max(maximum, bottles(cur + 1, memory, bottlesArray));
    }
    if(cur + 2 < bottlesArray.size()){
        maximum = max(maximum, bottlesArray[cur] + bottles(cur + 2, memory, bottlesArray));
    }

    return memory[cur] =  maximum;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n;
    cin >> n;
    vector<int> memory(n, -1);
    vector<int> bottleArray(n);
    for (int i = 0; i < n; ++i) {
        cin >> bottleArray[i];
    }

    cout << bottles(0, memory, bottleArray);
}