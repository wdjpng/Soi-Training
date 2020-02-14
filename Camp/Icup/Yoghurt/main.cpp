#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    int counter = 0;
    int base = 1;
    int maxCounter = (n + 1) / 2 - 1;
    vector<int>top;
    top.push_back(input[0]);
    while (counter < maxCounter) {
        int oldCounter = counter;
        counter += base;
        base *= 2;

        for (int i = oldCounter; i < counter; ++i) {
            input[2 * i + 1] = min(input[2 * i + 1], input[i] - 1);
            input[2 * i + 2] = min(input[2 * i + 2], input[i] - 1);
            top.push_back(input[2 * i + 1]);
            top.push_back(input[2 * i + 2]);
        }
    }


    sort(top.begin(), top.end());

    for (int curDay = 0; curDay < top.size(); ++curDay) {
        int curYog = top[curDay];
        if (curYog <= curDay) {
            cout << "no\n";
            exit(0);
        }
    }


    cout << "yes\n";
}