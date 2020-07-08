#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include <bits/stdc++.h>
using namespace std;
#define int long long
ifstream fin("/home/wdjpng/Pictures/bargain-sub5-attempt3.txt");
#define cin fin

vector<vector<int>>memory;
vector<int> buying, selling;
int maxMoney(bool hasCheese,int cur){
    if(memory[hasCheese][cur]!=-1){
        return memory[hasCheese][cur];
    }

    int whenNowBought, whenNowSold = numeric_limits<int>::min();
    int whenDoneNothing = maxMoney(hasCheese,cur+1);
    if(!hasCheese){
        whenNowBought = maxMoney(true,cur+1) -buying[cur];
    } else{
        whenNowSold = selling[cur] + maxMoney(false,cur+1);
    }


    return memory[hasCheese][cur] = max({whenNowBought, whenDoneNothing, whenNowSold});
}

// I have just increased the stack limit and I might have just uploaded binaries or something twice
signed main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; ++i) {
        int n, k;
        cin >> n >> k;
        buying = vector<int>(n);
        selling = vector<int>(n);
        memory = vector<vector<int>>(2, vector<int>(n, -1)) ;


        for (int j = 0; j < n; ++j) {
            cin >> buying[j] >> selling[j];
        }

        memory[0][n-1] = 0;
        memory[1][n-1] = selling[n-1];

        maxMoney(false, 0);

        cout << "Case #" << i << ": " << k *  memory[0][0] << "\n";

    }
}