#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define int long long

using namespace std;

//This solution gets 100/100 points in the grader

int getPossibilitiesForTwoRows(int len, vector<int> &memory, int &d){
    if(len == d){
        return 2;
    }
    if(len < d && len > 0){
        return 1;
    }
    if(len < 1){
        return 0;
    }

    if(memory[len] != -1){
        return memory[len];
    }
    return memory[len] = getPossibilitiesForTwoRows(len-1, memory, d) + getPossibilitiesForTwoRows(len-d, memory, d);
}

signed main() {
    int d, n;
    cin >> d >> n;

    if(d == 1 || n == 1){
        cout << 1;
        exit(0);
    }
    vector<int> memory(n + 1, -1);
   cout << getPossibilitiesForTwoRows(n, memory, d);




}
