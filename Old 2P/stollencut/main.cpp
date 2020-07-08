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

    int n, k;
    cin >> n >> k;
    vector<int>subsetsum(n+ 1);
    subsetsum[0] = 0;

    for (int i = 1; i < n+1; ++i) {
        cin >> subsetsum[i];
        subsetsum[i]+=subsetsum[i-1];
    }



    int minDifference = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        int start = 0;
        int end = i;
        while (start+1 < end){
            int cur = round((start+end)/2);

            if(subsetsum[i]-2*subsetsum[cur] > 0){
                start = cur;
            } else{
                end=cur;
            }
        }

        int cur = round((start+end/2));

        if(subsetsum[i]-2*subsetsum[cur] > 0){
            start = cur;
        } else{
            end=cur;
        }

        cur = round((start+end/2));;

        minDifference = min(minDifference, max(subsetsum[i] - subsetsum[cur], max(abs(subsetsum[n] - subsetsum[i+1] - subsetsum[cur]), abs(subsetsum[n] - subsetsum[i+1] - subsetsum[i]))));
    }

    cout << minDifference << "\n";
    exit(0);
}