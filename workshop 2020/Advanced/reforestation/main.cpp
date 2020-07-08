#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>

#define int long long
using namespace std;

int space(int distance){
    if(distance <= 2){
        return  0;
    }
    return (distance -1)/2;
}

signed main() {
    int n;
    cin >> n;

    priority_queue<pair<int, pair<int, int>>> treesToPlant; //Distance, indexStart, indexEnd
    treesToPlant.push(make_pair(0, make_pair(-1, -n)));

    while (treesToPlant.size() > 0){
        pair<int, pair<int, int>> cur = treesToPlant.top();
        treesToPlant.pop();

        cur.second.first = -cur.second.first;
        cur.second.second = -cur.second.second;

        if(cur.second.first > cur.second.second){
            continue;
        }

        int middle = (cur.second.first + cur.second.second) / 2;
        cout << middle << "\n";

        treesToPlant.push(make_pair(space(middle - cur.second.first), make_pair(-cur.second.first, -middle + 1)));
        treesToPlant.push(make_pair(space( cur.second.second - middle), make_pair(-middle -1, -cur.second.second)));
    }
}