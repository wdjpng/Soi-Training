#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(n<2){cout << -1; exit(0);}
    vector<int>out;
    if(n==2){
        if(a[0]==a[1]){
            cout << "1 " << a[0];
            exit(0);
        } else{
            if((a[0]+a[1])%2==0){
                out.push_back((a[0]+a[1])/2);
            }
            out.push_back(a[0]-(a[1]-a[0]));
            out.push_back(a[1]+(a[1]-a[0]));
        }
    } else{
        int dist = min(a[1]- a[0], a[2] - a[1]);
        for (int i = 1; i < n; ++i) {
            if(a[i] - a[i-1]==dist){ continue;}
            if(a[i] - a[i-1]==2*dist){out.push_back(a[i-1] + dist);
                continue;}

            cout << 0;
            exit(0);
        }
        if(dist == 0&&out.size()==0){
            cout << "1 " << a[0];
            exit(0);
        }
        if(out.size()>0){
            if(out.size()==1){
                cout << "1\n" << out[0];
            } else{
                cout << "0\n";
            }
            exit(0);
        }
        out.push_back(a[0]-dist);
        out.push_back(a[n-1]+dist);
    }

    sort(out.begin(), out.end());
    cout << out.size() << "\n";
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << " ";
    }
}