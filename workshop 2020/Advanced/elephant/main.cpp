#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>


#define int long long
using namespace std;

//I should really stop to just upload old code
vector<int> parent;
// finde den parent von x
int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}
// verbinde subgraph a mit b
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(rand()%2){
        parent[a] = b;
    }else{
        parent[b] = a;
    }
}
// finde den MST nach kruskal
int kruskal(vector<vector<pair<int,int> > > &graph){
    // Kanten speichern
    vector<pair<int,pair<int,int> > > edges;
    // Gesamtgewicht des Spannbaumens
    int weight = 0;

    // Alle Kanten aus dem Graphen (Adjazenzliste) auslesen
    // parent - Vektor initalisieren
    for(int i=0;i<(int)graph.size();i++){
        parent.push_back(i);
        for(int j=0;j<(int)graph[i].size();j++){
            int from = i;
            int to = graph[i][j].first;
            int w = graph[i][j].second;
            if(from > to){continue;}
            edges.push_back({w, {from, to}});
        }
    }
    // Alle Kanten nach Kantengewicht sortieren
    sort(edges.begin(), edges.end());

    // Alle Kanten für den MST betrachten
    for(int i=0; i<(int)edges.size();i++){
        int from = edges[i].second.first;
        int to = edges[i].second.second;
        int w = edges[i].first;

        // to und from sind bereits im selbem Subgraphen, d.h. verbunden
        if(find(to) == find(from)){
            continue;
        }
        // Kante ist Teil des Spannbaumes
        unite(to, from);
        weight += w;
    }
    return weight;
}

signed main() {
    int n, k;
    cin >> n >> k;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0; i< k; i++){
        int node1, node2, weight;

        cin >> node1 >> node2 >> weight;
        graph[node1-1].push_back({node2-1, weight});
        graph[node2-1].push_back({node1-1, weight});
        sum+= weight;
    }

    cout << sum - kruskal(graph) << "\n";

}