#include <iostream>

#include <math.h>
#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;

    bool isPrime = true;

    int sqr = sqrt(n);

    for (int i = 2; i < sqr + 1; ++i) {
        if(n%i == 0 && i!=n){
            isPrime = false;
            break;
        }
    }
    if(isPrime && n!= 1){
        cout << "prime\n";
    } else{
        cout << "composite\n";
    }
}