#include <iostream>
#include <vector>
#include <deque>
#include <limits>

#define int long long
using namespace std;

// This solution currently scores 50/100 points

vector<int> angerPrefixsum, loudnnessPrefixsum;
int n, k;
vector<vector<int>> memory;
int loudbus(int index, int remainingK){
    if(memory[index][remainingK] != -1){
        return memory[index][remainingK];
    }

    if(remainingK == 0){
        if(index > n){
            return 0;
        }
        return 10000000000000000;
    }



    int minLoudness = 10000000000000000;
    for (int i = index; i <= n - remainingK + 1; ++i) {
        minLoudness = min(minLoudness, (loudnnessPrefixsum[i] - loudnnessPrefixsum[index-1]) * (angerPrefixsum[i] - angerPrefixsum[index-1]) + loudbus(i+1, remainingK-1));
    }

    return memory[index][remainingK] = minLoudness;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n >> k;
    angerPrefixsum = vector<int>(n+1, 0);
    loudnnessPrefixsum = vector<int>(n+1, 0);
    memory = vector<vector<int>>(n+2, vector<int>(k+1, -1));
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;

        loudnnessPrefixsum[i] = loudnnessPrefixsum[i-1] + a;
        angerPrefixsum[i] = angerPrefixsum[i-1] + b;
    }

    cout << loudbus(1, k) << "\n";
}