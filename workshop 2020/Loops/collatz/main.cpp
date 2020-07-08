#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int k, i = 0;
    cin >> k;

    while (k!=1){
        i++;
        if(k%2==0){
            k/=2;
        } else{
            k=3*k+1;
        }
    }

    cout << i << "\n";
}