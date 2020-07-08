#include <iostream>
#include <map>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
#define int long long

ifstream fin("/tmp/arcmatch-sub3-attempt0.txt");
#define cin fin


void colorGraph(vector<vector<int>> &graph, vector<int> &colors, int start) {
    queue<int> queue;
    queue.push(start);
    colors[start] = start;
    while (queue.size() != 0) {
        int cur = queue.front();
        queue.pop();

        for (int i = 0; i < graph[cur].size(); ++i) {
            if (colors[graph[cur][i]] == -1) {
                colors[graph[cur][i]] = !colors[cur];
                queue.push(graph[cur][i]);
            } else if (colors[graph[cur][i]] == colors[cur]) {
                colors = {};
                return;
            }
        }
    }
}


vector<vector<int>> arcmatch(vector<int> &input) {
    vector<vector<int>> E(input.size() / 2);
    vector<int> endPositions(input.size() / 2, -1);

    for (int j = 0; j < input.size(); ++j) {
        endPositions[input[j]] = j;
    }

    priority_queue<int> firstEnds;
    stack<int> starts;
    starts.push(-1);
    firstEnds.push(-1);
    firstEnds.push(-1);

    for (int i = 0; i < input.size(); ++i) {
        int cur = input[i];
        while (starts.top() != -1 && endPositions[input[starts.top()]] >= i) {
            starts.pop();
        }

        if (i == endPositions[cur]) {
            firstEnds.pop();

            if (starts.top() != -1) {
                E[input[starts.top()]].push_back(cur);
                E[cur].push_back(input[starts.top()]);
            }
        } else {
            starts.push(i);

            int tmp = input.size() - firstEnds.top();
            firstEnds.pop();
            int tmp2 = input.size() - firstEnds.top();
            int element1 = input[tmp];
            int element2 = input[tmp];

            if (tmp != input.size() + 1) {
                if (endPositions[cur] > tmp) {
                    E[input[tmp]].push_back(cur);
                    E[cur].push_back(input[tmp]);
                }
            }

            if (tmp2 != input.size() + 1) {
                if (endPositions[cur] > tmp2) {
                    E[input[tmp2]].push_back(cur);
                    E[cur].push_back(input[tmp2]);
                }
            }

            firstEnds.push(input.size() - tmp);
            firstEnds.push(input.size() - endPositions[cur]);
        }
    }


    return E;
}

signed main() {
    /* // Turn off synchronization between cin/cout and scanf/printf
     ios_base::sync_with_stdio(false);
 // Disable automatic flush of cout when reading from cin cin.tie(0);
     cin.tie(0);*/

    int testCases;
    cin >> testCases;
    /* ofstream out("output.txt");
     streambuf *coutbuf = cout.rdbuf();
     cout.rdbuf(out.rdbuf());*/


    for (int testCase = 0; testCase < testCases; ++testCase) {

        int n;
        cin >> n;

        vector<int> input(2 * n);
        vector<int> endPositions(n);
        for (int j = 0; j < input.size(); ++j) {
            cin >> input[j];
            endPositions[input[j]] = j;
        }

        vector<vector<int>> E = arcmatch(input);
        vector<int> colors(n, -1);


        for (int i = 0; i < E.size(); ++i) {
            if (colors[i] == -1) {
                colorGraph(E, colors, i);

                if (colors.size() == 0) {
                    break;
                }
            }
        }

        if (colors.size()) {
            cout << "Case #" << testCase << ": Possible\n";
        } else {
            cout << "Case #" << testCase << ": Impossible\n";
        }
    }
}