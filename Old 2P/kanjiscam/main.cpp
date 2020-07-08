#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define int long long

using namespace std;

signed main() {
    int n, k;
    cin >> k >> n;

    cin.tie();
    ios_base::sync_with_stdio(false);

    vector<pair<int, int>>sum;
    for (int i = 0; i < k; ++i) {
        sum.push_back(make_pair(0,i));
    }

    vector<bool>canBeFirst(k, true);
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); ++j) {
            sum[input[j]-'a'].first+=pow(k, (input.size()-1-j));
        }
        canBeFirst[input[0] - 'a']=false;
    }

    sort(sum.begin(), sum.end());
    reverse(sum.begin(), sum.end());
    int curSum = 0;
    int first = -1;
    for (int i = 0; i < k; ++i) {
        if(canBeFirst[sum[i].second]){
            sum[i].first=0;
            first=sum[i].second;
            break;
        }
    }
    sort(sum.begin(), sum.end());
    reverse(sum.begin(), sum.end());

    for (int i = 0; i < k; ++i) {

        curSum+=(i+1)*sum[i].first;
    }

    cout << curSum << "\n";
}