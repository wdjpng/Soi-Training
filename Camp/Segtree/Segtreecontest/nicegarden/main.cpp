#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

vector<vector<int>>input;
int n, maxDifference;

int getRequiredDays(int lowest, int highest){
    int maxDays = 0;
    for (vector<int> flower : input){
        if(flower[0] < lowest){
            int curDays = ceil((max((int)0, lowest-flower[0]))/(double)flower[1]);
            maxDays = max(curDays, maxDays);
            if(flower[1] == 0){
                if(lowest > flower[0]){
                    return -1;
                }
                continue;
            }
            maxDays = max(curDays, maxDays);
        } else if (flower[0] > highest){
            if(flower[2] == 0){
                if(flower[0] > highest){
                    return -2;
                }
                continue;
            }
            int curDays = ceil((max((int)0, flower[0] - highest))/(double)flower[2]);
            maxDays = max(curDays, maxDays);
        }
    }

    return  maxDays;
}


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n >> maxDifference;

    input = vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
        int h, s, g;
        cin >> h >> s >> g;
        input[i] = {h, s, g};
    }


    int mini = 9999999999999;
    for (int i = 0; i < 100000; ++i) {
        int cur = getRequiredDays(i, i+maxDifference);
        if(cur != -1 && cur != -2){
            mini = min(mini, cur);
        }
    }

    cout << mini << "\n";

}