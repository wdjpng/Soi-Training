#include <iostream>
#include <vector>
#include <deque>
#include <limits>

#define int long long
using namespace std;



signed main() {
    int n;
    cin >> n;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> mast(n);
    for(int i = 0; i< n; i++){
        cin >> mast[i];
    }

    if(mast.size() < 3){
        cout << "yes\n";
        exit(0);
    }

   int steepness = mast[1] - mast[0];

    for (int j = 1; j < mast.size(); ++j) {
        if(mast[j] - mast[j-1] != steepness){
            cout << "no\n";
            exit(0);
        }
    }

    cout << "yes\n";
}