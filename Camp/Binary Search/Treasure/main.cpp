#include <bits/stdc++.h>

#define int long long
using namespace std;

const int INF = 1e13;

signed main() {
    int n, m;
    cin >> m >> n;

    int startX=0, startY=0, endX=m, endY=n;
    while (true){
        int curX = (startX+endX)/2;
        int curY = (startY+endY)/2;
        cout  << curX << " " << curY << endl;

        char result;
        cin >> result;

        if(result == 'T'){
            break;
        } else if (result == 'N'){
            startY=curY;
        } else if(result == 'E'){
            startX=curX;
        } else if(result == 'S'){
            endY=curY;
        } else if(result == 'W'){
            endX=curX;
        }
    }


}