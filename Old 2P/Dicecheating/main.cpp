#include <bits/stdc++.h>

#define int long long
using namespace std;

//Not finished
signed main() {
    int nOrg, nWish, sides;
    cin >> nOrg >> nWish >> sides;

    vector<int>diceOrg(nOrg);
    vector<int>diceWish(nWish);
    vector<int>add(sides);
    vector<int>remove(sides);
    vector<vector<int>>turnDistance(sides, vector<int>(sides));

    for (int i = 0; i < nOrg; ++i) {
        cin >> diceOrg[i];
    }

    for (int i = 0; i < nWish; ++i) {
        cin >> diceWish[i];
    }

    for (int i = 0; i < sides; ++i) {
        cin >> add[i];
    }

    for (int i = 0; i < sides; ++i) {
        cin >> remove[i];
    }

    for (int i = 0; i < sides; ++i) {
        for (int j = 0; j < sides; ++j) {
            cin >> turnDistance[i][j];
        }
    }

    for (int i = 0; i < sides; ++i) {
        for (int j = 0; j < sides; ++j) {
            for (int k = 0; k < sides; ++k) {
                turnDistance[i][j] = min(turnDistance[i][j], turnDistance[i][k] + turnDistance[k][j]);
            }
        }
    }

    vector<vector<int>>memory(nOrg+1, vector<int>(nWish+1));

    for (int i = 1; i < nOrg; ++i) {
        memory[i][0] = memory[i-1][0] + remove[diceOrg[i-1]];
    }

    for (int i = 1; i <= nWish; ++i) {
        memory[0][i] = memory[0][i-1] + add[diceWish[i-1]];
    }

    for (int curOrg = 1; curOrg <= nOrg; ++curOrg) {
        for (int curWish = 1; curWish <= nWish; ++curWish) {
            int removeCurOrg =  memory[curOrg-1][curWish] + remove[diceOrg[curOrg-1]];
            int addCurWish = memory[curOrg][nWish-1] + add[diceWish[curWish-1]];
            int changeCurRealToCurWish = memory[curOrg-1][curWish-1] + turnDistance[diceOrg[curOrg-1]][diceWish[curWish-1]];

            memory[curOrg][curWish] = min({removeCurOrg, addCurWish, changeCurRealToCurWish});
        }
    }

    cout << memory[nOrg][nWish];
}