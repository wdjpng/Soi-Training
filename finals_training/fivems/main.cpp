#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n; char action;
    cin >> action >> n;
    multiset<int>s;
    map<int, int>mp;
    int minn = 1e18;
    int maxx = -1e18;
    pair<int, int>maxOccurences=make_pair(0,0);
    auto med = s.begin();
    int medPos = 0;
    int sum=0;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        sum+=c;
        mp[c]++;
        maxOccurences=max(maxOccurences, make_pair(mp[c], c));
        s.insert(c);
        if(i==0){med=s.begin();}

        if(c < *med){medPos++;}
        if(medPos+1<(i+1)/2.0){
            medPos++;
            med++;
        }
        if(medPos+1>(i+2)/2){
            medPos--;
            med--;
        }

        minn=min(minn, c);
        maxx=max(maxx, c);

        if(action=='E'){
            cout << setprecision(10) << sum/((long double) i+1);
        } else if(action == 'I'){
            cout << minn;
        } else if(action == 'A'){
            cout << maxx;
        } else if(action == 'D'){
            cout << *med;
        } else if(action=='O'){
            cout << maxOccurences.second;
        }
        cout << "\n";
    }
}
