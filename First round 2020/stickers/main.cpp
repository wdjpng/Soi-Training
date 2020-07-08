#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;
#define int long long

ifstream fin("/home/wdjpng/Downloads/stickers-sub5-attempt0.txt");
#define cin fin

vector<vector<int>> memory;
int stickers(int cur, int remainingK, vector<pair<int,int>>& rarityVector){
    int n = rarityVector.size();
    if(cur >= n){
        return 0;
    }
    if(remainingK == 0){
        return -1;
    }
    if(cur == rarityVector.size()-1){
        if(remainingK > 0){
            return 0;
        } else{
            return -1;
        }
    }

    if(memory[cur][remainingK] != -2){
        return memory[cur][remainingK];
    }

    int costSum = 0;
    //Done nothing
    int minCost = stickers(cur+1, remainingK-1, rarityVector);
    if(minCost == -1){
        minCost = numeric_limits<int>::max();
    }
    for (int i = cur; i < n; ++i) {
        int costForRemainingStickers = stickers(i +1 , remainingK-1, rarityVector);

        costSum+=rarityVector[i].second * (rarityVector[cur].first - rarityVector[i].first);
        if(costForRemainingStickers==-1){
            continue;
        }

        int currentCost = costForRemainingStickers + costSum;

        if(currentCost < minCost){
            minCost = currentCost;
        }
    }

    if(minCost == numeric_limits<int>::max()){
        return memory[cur][remainingK] = -1;
    }

    return memory[cur][remainingK] = minCost;
}
signed main() {
    int testCases;
    cin >> testCases;

    freopen("output.txt","w",stdout);

    for (int i = 0; i < testCases; ++i) {
        int n, k;
        cin >> n >> k;

        map<int,int> rarity;

        for (int j = 0; j < n; ++j) {
            int family;
            cin >> family;
            if( rarity.find(family) == rarity.end()){
                rarity[family] = 0;
            }
            rarity[family]++;
        }

        memory = vector<vector<int>>(n+1, vector<int>(k + 1, -2));
        //In the form of key, numberOfElements
        vector<pair<int,int>> rarityVector;
        for (const auto& [key, value] : rarity) {
            rarityVector.push_back(make_pair(key, value));
        }

        sort(rarityVector.begin(), rarityVector.end());
        reverse(rarityVector.begin(), rarityVector.end());

        cout << "Case #" << i << ": " << stickers(0, k, rarityVector) << "\n";
    }
}