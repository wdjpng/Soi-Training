#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector<int>oldMemory(b.size(), 0);
    vector<int>newMemory(b.size(), 0);

    bool hadRightElement=false;
    for (int i = 0; i < b.size(); ++i) {
        oldMemory[i]=i+1;
        if(a[0]==b[i] || hadRightElement){
            hadRightElement=true;
            oldMemory[i]--;
        }
    }

    //I know this is ugly but I think it's faster to code than a proper solution
    vector<int>firstElementLookup(a.size(), 0);
    hadRightElement=false;
    for (int i = 0; i < a.size(); ++i) {
        firstElementLookup[i]=i+1;
        if(a[i]==b[0] || hadRightElement){
            hadRightElement=true;
            firstElementLookup[i]--;
        }
    }

    for (int i = 1; i < a.size(); ++i) {
        newMemory[0]=firstElementLookup[i];
        for (int j = 1; j < b.size(); ++j) {
            newMemory[j] = min({newMemory[j-1]+1, oldMemory[j]+1, oldMemory[j-1] + 1});
            if(a[i]==b[j]){
                newMemory[j]=oldMemory[j-1];
            }
        }

        oldMemory=newMemory;
    }

    cout << oldMemory[b.size()-1];
}