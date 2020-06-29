#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int>heights(n);
    vector<int>days(d);
    vector<pair<int, int>> sortedHeights;
    vector<bool>isFlooded(n);

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
        sortedHeights.push_back(make_pair(heights[i], i));
    }

    for (int i = 0; i < d; ++i) {
        cin >> days[i];
    }

    sort(sortedHeights.begin(), sortedHeights.end());
    int nextUpdate = 0;
    int regionCounter = 1;
    for (int day : days){
        for (int i = nextUpdate; i < n; ++i) {
            int curIndex = sortedHeights[i].second;
            if(sortedHeights[i].first <= day){
                isFlooded[curIndex] = true;

                int neighborCounter = 0;
                for (int move = -1; move < 2; ++move) {
                    if (move == 0) continue;
                    if(move + curIndex < 0 || move + curIndex >= n) continue;

                    if(!isFlooded[curIndex + move]){
                        neighborCounter++;
                    }
                }

                if(neighborCounter == 0){
                    regionCounter--;
                } else if (neighborCounter == 2){
                    regionCounter++;
                }
                nextUpdate=i+1;
            } else{
                nextUpdate = i;
                break;
            }
        }
        cout << regionCounter << " ";
    }
}