#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e12;

int totalCost;
vector<int>addedDistance;
void dijkstra(vector<vector<vector<int>>>const&E, int minYear, int cur, vector<int>& minCost){
    for(vector<int> next : E[cur]){
        if(minCost[next[0]] > minCost[cur] + next[1] && next[2]>=minYear){
            totalCost+=next[1];
            totalCost-=addedDistance[next[0]];
            addedDistance[next[0]]=next[1];
            minCost[next[0]]=minCost[cur] + next[1];
            dijkstra(E, minYear, next[0], minCost);
        }
    }
}

static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, m, budget;
    cin >> n >> m >> budget;
    map<string, int>map;
    int counter = 1;
    vector<vector<vector<int>>> E(n);

    for (int i = 0; i < m; ++i) {
        string nameA, nameB;
        int a, b, cost, constructionYear;
        cin >> nameA >> nameB >> cost >> constructionYear;
        if(map[nameA] == 0){
            a  = counter-1;
            map[nameA]=counter;
            counter++;
        } else{
            a = map[nameA]-1;
        }

        if(map[nameB] == 0){
            b  = counter-1;
            map[nameB]=counter;
            counter++;
        } else{
            b = map[nameB]-1;
        }

        E[a].push_back({b, cost, constructionYear});
        E[b].push_back({a, cost, constructionYear});
    }



    int start = 1900;
    int end = 2017 ;

    while (start+1<end){
        int curminYear=(start+end)/2;
        vector<int>minCost(n, MAX);
        minCost[0]=0;
        totalCost=0;
        addedDistance=vector<int>(n);
        dijkstra(E, curminYear, 0, minCost);
        bool everyNodeIsReachable = true;
        for(int dist : minCost){
            if(dist == MAX){
                everyNodeIsReachable=false;
                break;
            }
        }

        if(totalCost<=budget&&everyNodeIsReachable){
            start=curminYear;
        } else{
            end=curminYear;
        }
    }

    int curminYear=start;
    vector<int>minCost(n, MAX);
    addedDistance=vector<int>(n);
    minCost[0]=0;
    totalCost=0;
    dijkstra(E, curminYear, 0, minCost);

    cout << curminYear << " ";
    cout << totalCost << "\n";
}