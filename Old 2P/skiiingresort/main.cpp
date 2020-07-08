#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define int long long
#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int start, vector<vector<pair<int,int> > > &graph){
    int n = (int)graph.size();
    priority_queue<pair<int,int> > pq;
    vector<int> dist(n,-1);
    pq.push({0,start});
    dist[start] = 0;

    while(pq.size() != 0){
        int distance = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if(dist[pos] != -1 && dist[pos] < distance){
            continue;
        }

        for(int i=0; i < (int) graph[pos].size();i++){
            int next = graph[pos][i].first;
            int edge = graph[pos][i].second;

            if(dist[next] != -1 && dist[next] <= distance+edge){
                continue;
            }

            dist[next] = distance+edge;

            pq.push({-(distance+edge), next});
        }
    }

    return dist;
}

signed main() {
    int numberOfCrossings, numberOfLifts, numberOfPists;
    cin >> numberOfCrossings >> numberOfLifts >> numberOfPists;
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    //This will be in the form of maximal time till they have to be on the ofen, for how long and index
    vector<vector<pair<int,int> > > pists(numberOfCrossings);
    vector<vector<pair<int,int> > > lifts(numberOfCrossings);

    vector<vector<int>> toLifts(numberOfCrossings);

    vector<int> roots;
    for (int i = 0; i < numberOfLifts; ++i) {
        int firstCrossing, secondCrossing, time;
        cin >>firstCrossing >> secondCrossing >> time;
        lifts[firstCrossing].push_back(make_pair(secondCrossing, time));
        toLifts[secondCrossing].push_back(firstCrossing);
    }

    int removedEntries
    vector<string> output;
    int currentTime = 0;
    for (int j = 0; j < dyingTable.size(); ++j) {
        output.push_back(to_string(currentTime));
        if(currentTime > dyingTable[j][0]){
            cout << "Impossible";
            exit(1);
        }
        output.push_back(to_string(dyingTable[j][2]));
        currentTime+=dyingTable[j][1];
    }

    for (int k = 0; k < output.size(); ++k) {
        if(k%2==1){
            cout << output[k] << "\n";
        } else{
            cout << output[k] << " ";
        }
    }
}