#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int children, n;
    cin >> children >> n;

    vector<int> bags(n);
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        input %= children;
        bags[i] = input;
    }

    sort(bags.begin(), bags.end());
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        int toSearch = (children - bags[i]) % children;
        int startIndex = lower_bound(bags.begin(), bags.end(), toSearch) - bags.begin();
        if (startIndex != n && bags[startIndex] == toSearch) {
            int endIndex = upper_bound(bags.begin(), bags.end(), toSearch) - bags.begin();
            endIndex--;

            counter+=endIndex-startIndex+1;
            if(bags[i] == toSearch){
                counter--;
            }
        }
    }

    cout << counter / 2 << "\n";
}