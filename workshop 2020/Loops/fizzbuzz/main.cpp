#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        if(i%3==0 && i%5==0){
            cout << "FizzBuzz\n";
        } else if(i%3==0){
            cout << "Fizz\n";
        } else if(i%5==0){
            cout << "Buzz\n";
        } else{
            cout << i << "\n";
        }
    }

    int i = n;
    if(i%3==0 && i%5==0){
        cout << "FizzBuzz";
    } else if(i%3==0){
        cout << "Fizz";
    } else if(i%5==0){
        cout << "Buzz";
    } else{
        cout << i;
    }
}