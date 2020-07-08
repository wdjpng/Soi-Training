#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;

signed main() {
    string a, b = "uet*odn!";
    cin >> a;
    int offset = 0, counter=0;
    while (a[a.size() - 1] != '!') {
        cin >> a;
        for (int i = offset; i < offset + a.size(); ++i) {
            cout << b[i];
        }
        cout << "\n";
        for (int i = 0; i < counter; ++i) {
            cout << "   ";
        }
        offset += a.size();
        counter++;
    }
}