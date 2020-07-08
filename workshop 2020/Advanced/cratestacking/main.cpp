#include <iostream>
#include <vector>
#include <math.h>
#define int long long
using namespace std;


signed main() {
    int width, height, n;
    cin >> width >> height >> n;

    vector<vector<char>> stacks (100, vector<char>(100, '.'));
    vector<int> heights(100, 0);
    for (int i = 0; i < n; ++i) {
        int column;
        char name;
        cin >> column >> name;

        stacks[column][heights[column]] = name;
        heights[column]++;
    }

    for (int y = height-1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            cout<<stacks[x][y];
        }
       cout << "\n";
    }

    for (int j = 0; j < width; ++j) {
        cout << "#";
    }

}