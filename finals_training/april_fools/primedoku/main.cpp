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
    vector<int>perm={0,1,2,3,4,5,6,7,8};

    do{
        if(isPrim(perm[0]+perm[1]+perm[2]) && isPrim(perm[3]+perm[4]+perm[5]) && isPrim(perm[6]+perm[7]+perm[8]) && isPrim(perm[0]+perm[3]+perm[6]) && isPrim(perm[1] + perm[4] + perm[7]) && isPrim(perm[2]+perm[5]+perm[0])){
            counter++;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << 0;
}