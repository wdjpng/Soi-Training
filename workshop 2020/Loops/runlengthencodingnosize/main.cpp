#include <iostream>
#include <vector>
#include <deque>
#include <vector>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;

    int currentSum=0;
    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }
    for (int i = 0; i < n -1; ++i) {
        if(inputs[i] == inputs[i+1]){
            currentSum++;
        } else{
            cout << inputs[i] << " " << currentSum+1 << "\n";
            currentSum=0;
        }
    }
    cout << inputs[n-1] << " " << currentSum+1 << "\n";
}