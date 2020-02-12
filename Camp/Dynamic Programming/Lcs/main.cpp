#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

int n, m;
string A, B;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> n >> m >> A >> B;

    vector<int>oldMemory(m, 0);
    vector<int>newMemory(m);

    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
            newMemory[b]=oldMemory[b];
            if(A[a] == B[b]){
                newMemory[b]++;
            }
            if(b != 0){
                newMemory[b]=max(newMemory[b], newMemory[b-1]);
            }
        }
        oldMemory = newMemory;
        newMemory = vector<int>(m);
    }

    cout << oldMemory[m-1] << "\n";

}