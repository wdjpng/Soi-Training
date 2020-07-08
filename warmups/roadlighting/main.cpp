#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define int long long

using namespace std;

// Recursive implementation
int minLightingCostRecursive(vector<pair<int, int>> const &lights, vector<int> &memory, int cur) {
    if (cur < 0) {
        return 0;
    }
    if (memory[cur] != -1) {
        return memory[cur];
    }

    int minimalCost = numeric_limits<int>::max();
    for (auto &light:lights) {
        int currentCost = light.second + minLightingCostRecursive(lights, memory, cur - light.first);

        minimalCost = min(minimalCost, currentCost);
    }

    return memory[cur] = minimalCost;
}

//Iterative implementation
int minLightingCostIterative(vector<pair<int, int>> const &lights, int length) {

    vector<int> minCosts(length + 1, numeric_limits<int>::max());
    minCosts[0] = 0;

    for (int cur = 0; cur <= length; ++cur) {
        if (minCosts[cur] == numeric_limits<int>::max()) {
            continue;
        }
        for (auto &light : lights) {
            int maxLightedIndex = min(length, cur + light.first);
            minCosts[maxLightedIndex] = min(minCosts[maxLightedIndex], minCosts[cur] + light.second);
        }
    }

    return minCosts[length];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> lights;
    vector<int> memory(n, -1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        lights.push_back({a, b});
    }

    cout << minLightingCostIterative(lights, n);
}