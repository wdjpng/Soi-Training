#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m, k, q;
int find(int numberToFind, vector<int>& countries){
    if(numberToFind == countries[numberToFind]){
        return numberToFind;
    } else{
        return countries[numberToFind] = find(countries[numberToFind], countries);
    }
}

void unite(int a, int b, vector<int>& countries){
    int chefA = find(a, countries);
    int chefB = find(b, countries);


    if(rand()%2){
        countries[chefB] = chefA;
    } else{
        countries[chefA] = chefB;
    }

}


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
// Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);


    cin >> n >> m >> k >> q;

    vector<int>chefs(n);
    for (int i = 0; i < n; ++i) {
        chefs[i]=i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b, chefs);
    }

    for (int i = 0; i < n; ++i) {
        find(i, chefs);
    }

    vector<pair<int, int>>newValues;
    for (int i = 0; i < n; ++i) {
        newValues.push_back(make_pair(chefs[i], i));
    }

    sort(newValues.begin(), newValues.end());
    int start = 0;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if(i == n-1 || newValues[i+1].first != newValues[i].first){
            for (int j = start; j <= i; ++j) {
                newValues[j].first=counter;
            }
            counter++;
            start=i+1;
        }
    }

    for (int i = 0; i < n; ++i) {
        chefs[newValues[i].second]=newValues[i].first;
    }


    vector<vector<int>>connections(n);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a = chefs[a];
        b = chefs[b];

        if(a!=b){
            connections[a].push_back(b);
            connections[b].push_back(a);
        }
    }



    vector<vector<int>>queries;
    for (int j = 0; j < q; ++j) {
        int a, b;
        cin >> a >> b;
        queries.push_back({min(chefs[a], chefs[b]), max(chefs[a], chefs[b]), j});
    }
    sort(queries.begin(), queries.end());

    start = 0;
    vector<int> results(q);
    for (int i = 1; i < q; ++i) {
        if(queries[i-1][0] != queries[i][0]){
            vector<int>depth(k+2, 0);
            depth[queries[i-1][0]]=0;
            queue<int>queue;
            queue.push(queries[i-1][0]);
            while (queue.size()){
                int top = queue.front();
                queue.pop();
                for(int next : connections[top]){
                    if(depth[next] == 0 && next!= queries[i-1][0]){
                        depth[next]=depth[top]+1;
                        queue.push(next);
                    }
                }
            }
            for (int j = start; j < i; ++j) {
                results[queries[j][2]]=depth[queries[j][1]];
            }
            start=i;
        }
    }

    vector<int>depth(k+2, 0);
    depth[queries[q-1][0]]=0;
    queue<int>queue;
    queue.push(queries[q-1][0]);
    while (queue.size()){
        int top = queue.front();
        queue.pop();
        for(int next : connections[top]){
            if(depth[next] == 0 && next!= queries[q-1][0]){
                depth[next]=depth[top]+1;
                queue.push(next);
            }
        }
    }
    for (int j = start; j < q; ++j) {
        results[queries[j][2]]=depth[queries[j][1]];
    }

    for (int i = 0; i < q; ++i) {
        cout << results[i] << "\n";
    }
}