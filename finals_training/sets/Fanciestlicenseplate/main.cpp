#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> fancieness(const string &plate1) {
    int nomb1 = 0, group1 = 0, palin1 = 0;
    char last = ' ';
    vector<bool>hasOccured(10);
    int count = 0;
    int pow = 1;
    for (int i = 0; i < plate1.size(); ++i) {
        count += pow * (plate1[plate1.size() - 1 - i] - '0');
        pow *= 10;
        char c = plate1[i];
        if (c != last) {
            group1++;
            last = c;
        }
        if (!hasOccured[c]) {
            hasOccured[c] = true;
            nomb1++;
        }
        if (plate1[i] != plate1[plate1.size() - 1 - i]) { palin1++; }
    }

    return {nomb1, group1, palin1 / 2, count};
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    set<vector<int>> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string ac, plate;
        cin >> ac >> plate;
        vector<int> a = fancieness(plate);
        if (ac == "leave") {
            s.erase(a);
        } else {
            s.insert(a);
        }

        cout << (*s.begin())[3] << "\n";
    }
}
