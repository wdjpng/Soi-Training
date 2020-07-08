#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;


signed main() {
    int n, m;

    cin >> n >> m;

    cin.tie();
    ios_base::sync_with_stdio(false);

    vector<int> mice (n);

    for (int i = 0; i < n; ++i) {
        cin >> mice[i];

    }

    string output = "";

    sort(mice.begin(), mice.end());

    for (int j = n-1; j >= 0; --j) {
        cout << mice[j] << " ";
    }

    cout <<"\n";
}