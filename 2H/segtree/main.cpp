#include <iostream>
#include <vector>
#include <deque>
#include <limits>

#define int long long
using namespace std;

int e = numeric_limits<int>::min();
//YES, THIS IS COPY PASTE FROM YOUR WEBSITE BUT I HAVE READ IT CAREFULLY
int get(vector<vector<int>> &segtree, int l, int r){
    int a = l, b = r; // Indizes der linken und rechten Grenzen des Segmentes
    int v_l = e, v_r = e; // zusammengefasste Werte links und rechts
    for(int i = 0; a <= b; i++){
        if(a%2 == 1){ // Paar an linker Grenze nicht ganz überdeckt
            v_l = max(v_l, segtree[i][a]); // füge a zu kanonischer Überdeckung hinzu
            a++; // zu betrachtendes Segment wird kleiner
        }
        if(b%2 == 0){ // Paar an rechter Grenze nicht ganz überdeckt
            v_r = max(segtree[i][b], v_r); // füge b zu kanonischer Überdeckung hinzu
            b--; // zu betrachtendes Segment wird kleiner
        }
        a >>= 1, b >>= 1; // gehe eine Stufe nach oben
    }
    return max(v_l, v_r); // füge Werte von links und rechts zusammen
}

// führe auf Segmentbaum segtree die Zuweisung vᵢ← v aus
void set(vector<vector<int>> &segtree, int i, int v){
    segtree[0][i] = v; // setze Wert auf unterster Stufe
    int k = i>>1; // k ist Index des aktuell betrachteten Elternteils
    for(int l = 1; l < (int)segtree.size(); l++){ // aktualisiere Werte auf oberen Stufen
        if(k >= segtree[l].size()) break; // Elternteil existiert nicht, fertig
        segtree[l][k] = max(segtree[l-1][2*k], segtree[l-1][2*k+1]); // berechne Wert neu aus Werten der Kinder
        k >>= 1; // setze k auf Elternteil von k
    }
}

signed main() {

    int a = 1025;
    while (a!= 0){
        a>>=1;
        cout << a << "\n";
    }
}