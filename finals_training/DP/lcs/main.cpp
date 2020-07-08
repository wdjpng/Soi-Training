#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m;
    string A, B;
    cin >> n >> m >> A >> B;
    vector<int>oldMemory(m,0);
    vector<int>newMemory(m);


    for (int i = 0; i < n; ++i) {
        newMemory[0]=oldMemory[0];
        if(A[i] == B[0]){
            newMemory[0]=1;
        }
        for (int j = 1; j < m; ++j) {
           if(A[i] == B[j]){
               newMemory[j] = oldMemory[j-1]+1;
           } else{
               newMemory[j]=max(oldMemory[j], newMemory[j-1]);
           }
        }

        oldMemory=newMemory;
        newMemory=vector<int>(m, 0);
    }

    cout << oldMemory[m-1] << "\n";
}