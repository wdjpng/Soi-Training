#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include <bits/stdc++.h>
#define int long long

using namespace std;

ifstream fin("/home/wdjpng/Downloads/sbb-sub4-attempt0.txt");
#define cin fin

//Return the minimal distance between the first and the last node in the graph E
void shortestDistance(int start, vector<vector<pair<int,int>>>& E, vector<int>& depth) {
    queue<int> queue;
    queue.push(start);
    depth[start] = 0;
    while (queue.size() > 0){
        int cur = queue.front();
        queue.pop();

        //For every connected node
        for(int i = 0; i < E[cur].size(); i++){
            if(depth[E[cur][i].first] > E[cur][i].second + depth[cur] || depth[E[cur][i].first] == -1){
                queue.push(E[cur][i].first);
                depth[E[cur][i].first] = E[cur][i].second + depth[cur];
            }
        }
    }
}

vector<vector<int>> getAdjencyMatrix(vector<vector<pair<int, int>>>& E){
    int n = E.size();
    vector<vector<int>> adjencyMatrix(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        vector<int> depth(n, -1);
        shortestDistance(i, E, depth);
        adjencyMatrix[i] = depth;
    }

    return adjencyMatrix;
}

bool isCorrectSolution(vector<vector<pair<int, int>>>& E, vector<vector<int>>& correctAdjencyMatrix){
    vector<vector<int>> actualMatrix = getAdjencyMatrix(E);
    for (int i = 0; i < E.size(); ++i) {
        for (int j = 0; j < E.size(); ++j) {
            if(correctAdjencyMatrix[i][j]!=actualMatrix[i][j]){
                return  false;
            }
        }
    }

    return  true;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);
    int testCases;
    cin >> testCases;

    freopen("output.txt","w",stdout);
    for (int testCase = 0; testCase < testCases; ++testCase) {
        int n, m = 0;
        cin >> n;

        //Initial values
        vector<vector<int>> distancesToAchieve(n, vector<int>(n));
        // Input reading
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                cin >> distancesToAchieve[i][j];
            }
        }
        vector<vector<int>>  distancesToAchieveWithRemovement = distancesToAchieve;
        vector<vector<pair<int, int>>> currentE(n);
        vector<vector<pair<int, int>>> currentEInOneDirection(n);
        vector<int> alreadyAddedNodes(1,0);
        bool isSolution = true;
        while(!isCorrectSolution(currentE, distancesToAchieve)){
            //Find the smallest connection
            int smallestConnection = numeric_limits<int>::max();
            pair<int, int> itsIandJ;
            for (int i = 0; i < alreadyAddedNodes.size(); ++i) {
                for (int j = 0; j < distancesToAchieveWithRemovement[alreadyAddedNodes[i]].size(); ++j) {
                    if(distancesToAchieveWithRemovement[alreadyAddedNodes[i]][j] != 0 && distancesToAchieveWithRemovement[alreadyAddedNodes[i]][j]  < smallestConnection){
                        smallestConnection = distancesToAchieve[alreadyAddedNodes[i]][j];
                        itsIandJ = make_pair(alreadyAddedNodes[i], j);
                    }
                }
            }

            //Add the smallest possible connection because it has to be direct
            currentE[itsIandJ.first].push_back(make_pair(itsIandJ.second, smallestConnection));
            currentE[itsIandJ.second].push_back(make_pair(itsIandJ.first, smallestConnection));

            alreadyAddedNodes.push_back(itsIandJ.second);

            currentEInOneDirection[itsIandJ.first].push_back(make_pair(itsIandJ.second, smallestConnection));
            m++;

            //Remove all connections that are now satisfied
            vector<vector<int>> matrix = getAdjencyMatrix(currentE);

            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    if(matrix[k][i] == distancesToAchieve[k][i]){
                        distancesToAchieveWithRemovement[k][i] = 0;
                    } else if(matrix[k][i] < distancesToAchieve[k][i] && matrix[k][i]!=-1){
                        isSolution = false;
                    }
                }
            }
            if(!isSolution){
                break;
            }
        }
        if(isSolution && isCorrectSolution(currentE, distancesToAchieve)){
            cout << "Case #" << testCase << ": OK\n";
            cout << n << " " << m << " 0\n";
            for (int k = 0; k < currentEInOneDirection.size(); ++k) {
                for (int i = 0; i < currentEInOneDirection[k].size(); ++i) {
                    cout << k << " " << currentEInOneDirection[k][i].first << " " << currentEInOneDirection[k][i].second << "\n";
                }
            }
        } else{
            cout << "Case #" << testCase << ": Inconsistent\n";
        }
    }
}