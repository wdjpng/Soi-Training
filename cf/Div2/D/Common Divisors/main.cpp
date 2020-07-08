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
    int n = a.size();

    int min;
    for (int i = 1; i <= n; ++i) {
        if(n%i){ continue;}
        bool hasSol=true;
        for (int j = 0; j < n; ++j) {
            if(a[j]!=a[j%i]){
                hasSol=false;
                break;
            }
        }
        if(hasSol){
            min = i;
            break;}
    }

    for (int i = 0; i < b.size(); ++i) {
        if(b[i]!=a[i%min]){
            cout << "0";
            exit(0);
        }
    }

    int sum = 0;
    for (int i = 1; i <= 100000; ++i) {
        if(a.size()%(min*i)==0&&b.size()%(min*i)==0){sum++;}
    }

    cout << sum;
}