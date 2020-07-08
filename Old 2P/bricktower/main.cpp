#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define int long long

using namespace std;

string bricktower(int n){
    for (int i = 2; i < n/2; ++i) {
        int newNumber = (int) (n - (pow(i,2) - i)/2);
        bool isPossible = (newNumber%i) == 0;
        if(isPossible){
            return to_string(i);
        }
    }

    return "IMPOSSIBLE";
}

signed main() {
    int n;
    cin >> n;

    cin.tie();
    ios_base::sync_with_stdio(false);


    for (int i = 1; i < 100000; ++i) {
        cout << i << ": " << bricktower(i) << "\n";
    }
}