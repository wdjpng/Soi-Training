#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;


signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;

    int currentCs = 0;
    int currentBCs = 0;
    int currentABCs = 0;

    for (int i = S.length(); i >= 0; --i) {
        switch(S[i]){
            case 'c': {
                currentCs++;
                break;
            }
            case 'b': {
                currentBCs+=currentCs;
                break;
            }
            case 'a': {
                currentABCs+=currentBCs;
                break;
            }
        }
    }

    cout << currentABCs;
}