#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

int space(int distance){
    if(distance <= 2){
        return  0;
    }
    return (distance -1)/2;
}

signed main() {
    int n;
    cin >> n;

    vector<pair<int, int>> inputs;

    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;

        if(input > 0){
            inputs.push_back({input, 0});
        } else{
            inputs.push_back({-input, 1});
        }
    }

    sort(inputs.begin(), inputs.end());
    reverse(inputs.begin(), inputs.end());

    for (int i = 0; i < n; ++i) {
        if(inputs[i].second){
            cout << - inputs[i].first << " ";
        } else{
            cout << inputs[i].first << " ";
        }
    }
    cout << "\n";
}