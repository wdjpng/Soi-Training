#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

signed main() {
    string message;
    cin >> message;
    int n = message.length();
    vector<int>memory(n);

    if(n==1){
        cout << 1;
        exit(0);
    }

    memory[0]=1;
    memory[1]=1;
    if(10*(message[0]-'0') + message[1] - '0' <= 26){
        memory[1]++;
    }
    for (int i = 2; i < n; ++i) {
        memory[i]=memory[i-1];
        if(10*(message[i-1]-'0') + message[i] - '0' <= 26){
            memory[i]+=memory[i-2];
        }
        memory[i]%=(int)1e9+7;
    }
    cout << memory[n-1] << "\n";
}