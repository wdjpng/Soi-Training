#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>in(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> in[i];
    }

    int numNotIncreasing=0;
    int index=0;
    for (int i = 1; i < n-1; ++i) {
        if(in[i]<=in[i-1]){
            numNotIncreasing++;
            index=i;
        }
    }

    for (int j = 0; j < n-2; ++j) {
        index++;
        index%=(n-1);
        int last=(index+n-2)%(n-1);
        if(in[last]>=in[index]){
            cout <<"lies!";
            exit(0);
        }
    }
    if(numNotIncreasing>1){
        cout <<"lies!";
        exit(0);
    }

    vector<bool>exists(n);
    for (int i = 0; i < n-1; ++i) {
        exists[in[i]]=true;
    }

    int var=-1;
    for (int i = 0; i < n; ++i) {
        if(!exists[i]){
            if(var>=0){
                cout <<"lies!";
                exit(0);
            }
            var=i;
        }
    }
    cout << "print page " << var;
}