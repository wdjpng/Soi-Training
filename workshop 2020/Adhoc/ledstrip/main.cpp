#include <bits/stdc++.h>


using namespace std;
//This is mainly a joke submission, I think it would be funny if it worked
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, g, t;
    cin >> n >> g >> t;
    string cur;
    cin >> cur;
    cout << t << "\n";
    int actionCounter = 0;
    for (int i = 1; i < n; ++i) {
        if(cur[i-1] == cur[i]){
            actionCounter++;
            if(cur[i]=='0'){
                cur[i-1]='1';
                cur[i]='1';
            } else{
                cur[i-1]='0';
                cur[i]='0';
            }

            cout << i+1 << "\n";
            if(actionCounter==t){
                break;
            }
        }
    }

    cout << cur;
}