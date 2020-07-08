#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

#define int long long
using namespace std;

signed main() {
    int n;

    cin >> n;
    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }

    int sum = 1;
    vector<pair<int, int>> encoding;
    for (int j = 1; j < n; ++j) {
        if(inputs[j] != inputs[j-1]){
            encoding.push_back({inputs[j - 1], sum});
            sum = 1;
        } else{
            sum++;
        }
    }

    encoding.push_back({inputs[n-1], sum});

    cout << encoding.size() << "\n";
    for (int i = 0; i < encoding.size(); ++i) {
        cout << encoding[i].first << " " << encoding[i].second << "\n";
    }
}