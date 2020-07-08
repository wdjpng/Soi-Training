#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int a, b;
    cin >> a >> b;

    if (a > b) {
        cout << ">\n";
    } else if (a == b) {
        cout << "=\n";
    } else {
        cout << "<\n";
    }
}