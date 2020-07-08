#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

int lilypad(int cur, vector<int>& memory, vector<int>const& lilypads){
    if(cur < 0){
        return 0;
    }

    if(cur == 0){
        return lilypads[cur];
    }

    if(memory[cur] != -1){
        return  memory[cur];
    }

    int option1 = lilypad(cur-1, memory, lilypads);
    int option2 = lilypads[cur] + lilypad(cur-3, memory, lilypads);

    return memory[cur] = max(option1, option2);
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    int n, c;
    cin >> n >> c;
    vector<int> memory(n, -1);
    vector<int> lilypads(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> lilypads[i];
        if(lilypads[i] > c){
            lilypads[i] = 0;
        }
    }


    cout << lilypad(n-1, memory, lilypads);
}