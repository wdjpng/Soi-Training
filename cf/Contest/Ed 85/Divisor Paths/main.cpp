#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int d, q;
    cin >> d >> q;

    vector<int> divisors1;
    deque<int> divisors2;
    for (int i = 1; i < 40000000; ++i) {
        if (d % i == 0) {
            divisors1.push_back(i);
            divisors2.push_back(d / i);
        }
    }

    for (int i = 0; i < divisors2.size(); ++i) {
        divisors1.push_back(divisors2.front());
        divisors2.pop_front();
    }

    int n = divisors1.size();
    map<int, vector<int>> divisorDivisors;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= sqrtf(divisors1[i]); ++j) {
            if (divisors1[i] % j == 0) {
                divisorDivisors[divisors1[i]].push_back(j);
            }
        }
    }

    vector<vector<pair<int, int>>> E(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (divisors1[j] % divisors1[i] == 0) {
                int a = divisorDivisors[divisors1[j]].size();
                int b = divisorDivisors[divisors1[i]].size();
                if (a - b > 1) { continue; }
                int weight
            }
        }
    }
}