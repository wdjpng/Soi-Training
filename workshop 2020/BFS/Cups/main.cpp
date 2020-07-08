#include <bits/stdc++.h>

#define int long long

using namespace std;

int N;

vector<int> numToVector(int cur) {
    int a = cur % 301;
    int b = ((cur - a) % (301 * 301))/301;
    int c = (cur - a - 301*b)/301/301;

    if (N == 2) {
        return {a, b};
    }
    return {a, b, c};
}

int vectorToNum(vector<int> vec) {
    int sum=0;
    int counter = 1;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i] * counter;
        counter *= 301;
    }

    return sum;
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int T, V;
    cin >> T >> V >> N;

    queue<int> q;
    vector<int> depth(301 * 301 * 301 + 1, -1);
    vector<int> parents(301 * 301 * 301 + 1, -1);
    q.push(0);
    depth[0] = 0;
    vector<int> volumes(N);
    for (int i = 0; i < N; ++i) {
        cin >> volumes[i];
    }
    while (q.size()) {
        int cur = q.front();
        q.pop();

        vector<int> fillLevels = numToVector(cur);
        for (int i = 0; i < N; ++i) {
            if (fillLevels[i] == V) {
                cout << depth[cur] << "\n";
                int child = cur;
                vector<string> output;
                while (child != -1) {
                    string curString;
                    vector<int> result = numToVector(child);
                    curString += "(" + to_string(result[0]) + "," + to_string(result[1]);
                    if (N == 3) {
                        curString += "," + to_string(result[2]);
                    }
                    curString += ")\n";
                    output.push_back(curString);
                    child = parents[child];
                }
                reverse(output.begin(), output.end());
                for (int i = 0; i < output.size() && T % 2 == 0; ++i) {
                    cout << output[i];
                }
                exit(0);
            }


        }
        vector<int> possibleNewStates;
        for (int i = 0; i < N; ++i) {
            vector<int> possibleState = fillLevels;
            possibleState[i] = 0;
            possibleNewStates.push_back(vectorToNum(possibleState));

            possibleState[i] = volumes[i];
            possibleNewStates.push_back(vectorToNum(possibleState));

            for (int j = 0; j < N; ++j) {
                if(i==j){ continue;}
                possibleState=fillLevels;

                int added = min(volumes[j] - fillLevels[j], fillLevels[i]);
                possibleState[i] = fillLevels[i] - added;
                possibleState[j] = fillLevels[j] + added;

                possibleNewStates.push_back(vectorToNum(possibleState));
            }
        }

        for (int i = 0; i < possibleNewStates.size(); ++i) {
            if(depth[possibleNewStates[i]] == -1){
                parents[possibleNewStates[i]]=cur;
                depth[possibleNewStates[i]]=depth[cur]+1;
                q.push(possibleNewStates[i]);
            }
        }
    }

    cout << ":-(\n";
}