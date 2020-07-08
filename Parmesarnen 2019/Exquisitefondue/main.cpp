#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define int long long

using namespace std;


void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& output, int& counter){
    if(visited[start]){
        return;
    }
    bool hasResult=false;
    for (int j = 0; j < graph[start].size(); ++j) {
        for (int i = 0; i < output.size(); ++i) {
           if(output[i] == graph[start][j]){
               hasResult= true;
               break;
           }
        }
        if (hasResult){
            counter++;
            break;
        }
    }

    deque<int> queue;
    queue.push_back(start);
    output.push_back(start);
    visited[start] = true;

    while (queue.size()!=0){
        int cur = queue.back();
        queue.pop_back();

        for (int i = 0; i < graph[cur].size(); ++i) {
            if(!visited[graph[cur][i]]){
                queue.push_back(graph[cur][i]);
                visited[graph[cur][i]] = true;
                counter++;
                output.push_back(graph[cur][i]);
            }
        }
    }
}

bool isRightElemnt(vector<int> vector1, int& element, int value){
    if(vector1.size() == 0){
        return true;
    }
    if(vector1.size() == 1){
        if(value >= vector1[0]){
            if(element == 1){
                return true;
            } else{
                return false;
            }
        } else{
            if(element == 1){
                return false;
            } else{
                return true;
            }
        }
    }
    if(vector1.size() == element+1 && vector1[vector1.size()-1] < value){
        return true;
    }

    if(vector1.size() == 0 && vector1[vector1.size()-1] < value){
        return true;
    }

    return false;
}
signed main() {
    int n;
    cin >> n;

    cin.tie();
    ios_base::sync_with_stdio(false);

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> output;
    int counter = 0;

    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < k; ++i) {
            bool isConnected;

            cin >> isConnected;

            if(isConnected){
                graph[k].push_back(i);
                graph[i].push_back(k);
            }
        }
    }

    for (int l = 0; l < n; ++l) {
        sort(graph[l].begin(), graph[l].end());
    }
    for (int i = 0; i < visited.size(); ++i) {
        if(!visited[i]){
            dfs(i, graph, visited, output,counter);
        }
    }


    cout << counter << "\n";

    for (int j = 0; j < n; ++j) {
        cout << output[j] << " ";
    }
}