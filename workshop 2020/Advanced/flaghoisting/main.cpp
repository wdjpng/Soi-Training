#include <iostream>
#include <map>
#include <math.h>
#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;
    i00nt sum =2;

    int a = 0;
    for (int i = 0; i < 10000; ++i) {
        a+=pow(10, i);
    }


    if(sum%2==0){
        cout << "....o\n....|\n....|\n....|\n....|\n....|\n####|\n####|\n####|\n....|\n";
    } else{
        cout << "....o\n####|\n####|\n####|\n....|\n....|\n....|\n....|\n....|\n....|\n";
    }
}