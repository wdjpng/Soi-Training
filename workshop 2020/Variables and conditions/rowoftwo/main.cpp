#include <iostream>
#include <vector>
#include <deque>
#include <limits>

#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;

    if(n%2==0){
        cout << "L\n";
    } else{
        cout << "R\n";
    }
}