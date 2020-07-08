#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int curT = 0; curT < t; ++curT) {
        int n;

        cin >> n;
        priority_queue<pair<int, int>>pq;
        pq.push(make_pair(n, 0));
        vector<int>a(n);
        for (int i = 0; i < n; ++i) {
            pair<int, int>cur=pq.top();
            pq.pop();
            int len=cur.first;
            int l = -cur.second;
            int r = len+r;
            int isEven = len%2;
            if(isEven){isEven--;}
            else{isEven++;}
            a[l + len/2-isEven]=i+1;
            pq.push(make_pair(len/2-isEven, -l));
            pq.push(make_pair(len/2, -(l + len/2-isEven+1)));
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}