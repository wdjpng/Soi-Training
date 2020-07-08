#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

#define int long long

using namespace std;

//This solution gets 100/100 points in the grader

int distance(int a, int  b){
    if(a > b){
        return a-b;
    }

    return b-a;
}
signed main() {
    int n, k;
    cin >> n >> k;

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int lowestWork = 99999999999999999;
    int currentWork = 0;
    int oldWorkDifference = -n;
    int currentWorkDifference = -n;
    int currentDistanceBetweenPoints;



    vector<int> points(n);
    vector<int> error;
   if(k>0){
       k=-k;
       for (int i = 0; i < n; ++i) {
           cin >> points[i];
       }
       reverse(points.begin(), points.end());
       for (int j = 0; j < n; ++j) {
           error.push_back(points[j]-k*j);
           currentWork+=distance(points[j], j*k-1000000000);
       }
   } else{
       for (int i = 0; i < n; ++i) {
           cin >> points[i];
           error.push_back(points[i]-k*i);
           currentWork+=distance(points[i], i*k-1000000000);
       }
   }
    lowestWork= currentWork;

    sort(error.begin(), error.end());
    
    currentDistanceBetweenPoints = distance(-1000000000, error[0]);

    for (int i = 0; i < error.size() - 1; ++i) {
        if (error[i] != error[i+1]) {
            currentWorkDifference+=2;
            currentWork += oldWorkDifference*currentDistanceBetweenPoints;
            if (currentWork < lowestWork) {
                lowestWork = currentWork;
            }
            currentDistanceBetweenPoints = distance(error[i], error[i+1]);
            oldWorkDifference = currentWorkDifference;
        } else{
            currentWorkDifference+=2;
        }
    }
    currentWorkDifference+=2;
    currentWork += oldWorkDifference*currentDistanceBetweenPoints;
    if (currentWork < lowestWork) {
        lowestWork = currentWork;
    }
    cout << lowestWork;
}