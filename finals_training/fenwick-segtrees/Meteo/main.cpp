#include <bits/stdc++.h>

#define int long long

using namespace std;
vector<vector<vector<int>>> mem;
vector<vector<vector<int>>>val;
int l, b, h;
int get(int x, int y, int z) {
    if(x<1||y<1||z<1){return 0;}
    int r = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            for (int i1 = z; i1 > 0; i1 -= i1 & -i1)
                r += mem[i][j][i1];

    return r;
}

// increment a[k][l] by x
void add(int x, int y, int z, int increment) {
    int orgInc=increment;
    increment-=val[x-1][y-1][z-1];
    for (int i = x; i <= l; i += i & -i)
        for (int j = y; j <= b; j += j & -j)
            for (int i1 = z; i1 <= h; i1 += i1 & -i1)
                mem[i][j][i1]+=increment;

    val[x-1][y-1][z-1]=orgInc;
}

int getStalaktit(int x, int y, int x2, int y2, int z){
    int res=get(x2,y2,z);
    res-= get(x-1, y2, z) + get(x2, y-1, z);
    res+=get(x-1, y-1, z);
    return res;
}

int getQuader(int x, int y, int z, int x2, int y2, int z2){
    return getStalaktit(x,y,x2, y2, z2) - getStalaktit(x,y,x2, y2, z-1);
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    //ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    cin >> l >> b >> h;
    mem=vector<vector<vector<int>>>(l+1, vector<vector<int>>(b+1, vector<int>(h+1)));
    val=vector<vector<vector<int>>>(l+1, vector<vector<int>>(b+1, vector<int>(h+1)));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < l; ++k) {
                int inc;
                cin >> inc;

                add(k+1, j+1, i+1, inc);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char c;
        int x, y, z;
        cin >> c >> x >> y >> z;
        x++;y++;z++;
        if(c=='C'){
            int d;
            cin >> d;
            add(x, y, z, d);
            continue;
        }


        int x2, y2, z2;
        cin >> x2 >> y2 >> z2;
        long double res = getQuader(x,y,z,x2, y2, z2);
        res/=((long double)((x2-x+1)*(y2-y+1)*(z2-z+1)));
        cout << setprecision(10) << res << "\n";
    }
    
}
