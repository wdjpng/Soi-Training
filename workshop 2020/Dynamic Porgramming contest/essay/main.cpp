#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

#define int long long
using namespace std;
vector<int> lengths;

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, maxLength;
    cin >> n >> maxLength;

    lengths.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
        for (int j = 0; j < lengths[i]; ++j) {
            string a;
            cin >> a;
        }
    }

    vector<bool>isReachableOld(maxLength+1, false);
    vector<bool>isReachableNew(maxLength+1, false);
    
    isReachableOld[0] = true;
    isReachableOld[lengths[0]] = true;
    int maxReachable = lengths[0];
    for (int cur = 1; cur < n; ++cur) {
        for (int curWords = 0; curWords <= maxLength; ++curWords) {
            if(isReachableOld[curWords]){
                isReachableNew[curWords]=true;
                if(lengths[cur]+curWords>maxLength){ continue;}

                isReachableNew[curWords+lengths[cur]]=true;
                maxReachable=max(maxReachable, curWords+lengths[cur]);
            }
        }
        isReachableOld=isReachableNew;
        isReachableNew=vector<bool>(maxLength+1, false);
    }

    cout << maxReachable << "\n";
}