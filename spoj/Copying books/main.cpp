#include <bits/stdc++.h>

#define int long long
using namespace std;
//Not solved
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, p;
        cin >> n >> p;

        vector<int>books(n);
        int minTime = 0;
        for (int j = 0; j < n; ++j) {
            cin >> books[j];
            minTime=max(minTime, books[j]);
        }

        int start = minTime, end = 1e13;
        while (end - start > 1){
            int cur = (start+end)/2, scribeCounter = 0;
            for (int j = 0; j < n; ++j) {
                int sum=0;
                for (; j < n; ++j) {
                    if(sum+books[j]<=cur){
                        sum+=books[j];
                    } else{
                        j--;
                        break;
                    }
                }
                scribeCounter++;
            }

            if(scribeCounter <= p){
                end=cur;
            } else{
                start=cur;
            }
        }

        int cur = end;
        int sum=0, scriberCounter=0;
        vector<bool>shouldSeparateAfter(n, false);
        for (int j = n-1; j >= 0; --j) {
            for (; j >= 0; --j) {
                if(sum+books[j]<=cur&&p-scriberCounter-1<=(j)){
                    sum+=books[j];
                } else{
                    shouldSeparateAfter[j]=true;
                    j++;
                    sum=0;
                    break;
                }
            }
            scriberCounter++;
        }

        for (int j = 0; j < n; ++j) {
            cout << books[j] << " ";
            if(shouldSeparateAfter[j]){
                cout << "/ ";
            }
        }
        cout << "\n";
    }
}