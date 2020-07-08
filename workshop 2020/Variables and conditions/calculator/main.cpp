#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int op, a, b;
    cin >> op >> a >>b;

    if(op == 0){
        cout << a+b << "\n";
    } else if (op == 1){
        cout << a-b << "\n";
    } else{
        cout << a*b << "\n";
    }
}