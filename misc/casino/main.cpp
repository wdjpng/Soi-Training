#include <iostream>
#include <vector>

#define int long long
using namespace std;


int dfs(vector<vector<int>>& adjencyList, int v, int& maxValue, vector<bool>& visited, vector<int>& jackpots){
    if(jackpots[v] > maxValue){
        maxValue = jackpots[v];
    }
    for(int e = 0; e < adjencyList[v].size(); e++) {
        int w = adjencyList[v][e];
        // Nun prüfen wir ob der Nachbar w noch unbesucht ist.
        if(!visited[w]) {
            visited[w] = true;
            dfs(adjencyList, w, maxValue, visited, jackpots);
        }
    }

    return maxValue;
}

void casino(vector<vector<int>> adjencyList, vector<int> jackpots){
    vector<bool> visited (jackpots.size(), false);
    vector<int> maximalPrize;

    for (int j = 0; j < visited.size(); ++j) {
        if(!visited[j]){
            int zero = 0;
            maximalPrize.push_back(dfs(adjencyList, j, zero, visited, jackpots));
        }
    }

    int prize = 0;

    for (int i = 0; i < maximalPrize.size(); ++i) {
        prize+=maximalPrize[i];
    }

    cout << prize << "\n";
}

signed main() {
    int n,m;

    cin >> n >> m;

    vector<vector<int>> adjencyList (n);
    vector<int> jackpots(n);

    for(int i = 0; i < jackpots.size(); i++){
        cin >> jackpots[i];
    }

    for(int i = 0; i < m; i++){
        int casino1, casino2;

        cin >> casino1 >> casino2;

        adjencyList[casino1].push_back(casino2);
        adjencyList[casino2].push_back(casino1);
    }


    casino(adjencyList, jackpots);
}