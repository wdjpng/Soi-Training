#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    string mode;
    int number;
    cin >> mode >> number;


    if(mode[0] == 'E'){
        int exponent = 0;
        string output = "";
        while (pow(5, exponent + 1) <= number){
            exponent++;
        }

        for (int currentExponent = exponent; currentExponent >= 0; --currentExponent) {
            for (int multiplicator = 1; multiplicator < 6; ++multiplicator) {
                if(pow(5, currentExponent) * multiplicator > number){
                    output+=to_string((multiplicator-1) * 2);
                    number-=pow(5, currentExponent) * (multiplicator - 1);
                    break;
                }
            }
        }

        cout << output << "\n";
    } else{
        string numberToString = to_string(number);
        int decimal = 0;
        for (int i = 0; i < numberToString.size(); ++i) {
            decimal+= (int) pow(5, i) * ((numberToString[numberToString.size() - 1 -i] - '0') / 2);
        }

        cout  << decimal << "\n";
    }
}
