#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>


#define int long long
using namespace std;

// I should first look at my old code before uploading,
// I have no idea how I could code so wrong one year ago
vector<int>parent;
int find(int a){
    if(parent[a] == a){
        return a;
    }

    return parent[a] = find(parent[a]);
}

int unite(int a, int b){
    a = find(a);
    b = find(b);

    if(rand() % 2 == 0){
        return parent[a] = b;
    } else{
        return parent[b] = a;
    }
}

signed main() {
    int n, k;
    cin >> n >> k;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; ++i) {
        parent.push_back(i);
    }

    vector<pair<int, pair<int, int>>> edges;

    int weightSum = 0;
    for(int i = 0; i< k; i++){
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        weightSum+=weight;
        edges.push_back(make_pair(weight, make_pair(node1-1, node2-1)));
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); ++i) {
        if(find(edges[i].second.first) != find(edges[i].second.second)){
            unite(edges[i].second.first, edges[i].second.second);
            weightSum-=edges[i].first;
        }
    }

    cout << weightSum << "\n";
}