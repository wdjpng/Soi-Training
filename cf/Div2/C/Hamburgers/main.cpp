#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string a;
    int r;
    cin>>a;
    vector<int>there(3);
    vector<int>shop(3);
    vector<int>needed(3);
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]=='B'){needed[0]++;}
        if(a[i]=='S'){needed[1]++;}
        if(a[i]=='C'){needed[2]++;}
    }
    for (int i = 0; i < 3; ++i) {
        cin >> there[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> shop[i];
    }
    cin >> r;

    int start=0, end=1e15;
    for (int z = 0; z < 100; ++z) {
        int cur = (start+end)/2;
        int neededR=0;
        for (int i = 0; i < 3; ++i) {
            neededR+=shop[i]*(max((int)0, needed[i]*cur-there[i]));
        }

        if(neededR>r){
            end=cur;
        } else{
            start=cur;
        }
    }

    cout << start;
}