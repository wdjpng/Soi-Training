#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> tmpInput(n);
    map<int, int>occurences;
    for (int i = 0; i < n; ++i) {
        cin >> tmpInput[i];
        occurences[tmpInput[i]]++;
    }
    sort(tmpInput.begin(), tmpInput.end());

    vector<pair<int, int>>input;//Value, occurences
    input.push_back(make_pair(tmpInput[0], 1));

    int offSet = 0;
    for (int i = 1; i < n+offSet; ++i) {
        if(input[i-1-offSet].first == tmpInput[i]){
            input[i-1-offSet].second++;
            offSet++;
            n--;
        } else{
            input.push_back(make_pair(tmpInput[i], 1));
        }
    }
    int combinationSum = 0;

    for (int i = 0; i < n - 2; ++i) {
        int curCombinations = 0;
        int headIndex = i + 2;

        for (int bIndex = i + 1; bIndex < n - 1; ++bIndex) {
            if(headIndex==n){
                break;
            }

            while (input[headIndex].first < input[i].first + input[bIndex].first && headIndex!=n-1) {
                headIndex++;
            }

            if(headIndex==n){
                break;
            }

            while (input[headIndex].first == input[i].first + input[bIndex].first) {
                if(headIndex==n){
                    break;
                }

                curCombinations+=input[headIndex].second*input[bIndex].second*input[i].second;
                headIndex++;
            }
        }

        combinationSum += curCombinations;
    }

    for (int i = 0; i < n; ++i) {
        if(input[i].second >= 2 && occurences[2*input[i].first]){
            combinationSum+=occurences[2*input[i].first]*((input[i].second)*(input[i].second-1)/2);
        }
    }

    cout << combinationSum << "\n";
}