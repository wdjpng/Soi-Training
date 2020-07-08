#include <bits/stdc++.h>

#define int long long
using namespace std;

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

    for (int k = 0; k < sides; ++k) {
        for (int i = 0; i < sides; ++i) {
            for (int j = 0; j < sides; ++j) {
                turnDistance[i][j] = min(turnDistance[i][j], turnDistance[i][k] + turnDistance[k][j]);
            }
        }
    }

    for (int i = 0; i < sides; ++i) {
        for (int j = 0; j < sides; ++j) {
            add[i] = min(add[i], turnDistance[j][i] + add[j]);
            remove[i] = min(remove[i], turnDistance[i][j] + remove[j]);
        }
    }

    vector<vector<int>>memory(nOrg+1, vector<int>(nWish+1, 0));

    for (int i = nOrg-1; i >= 0; --i) {
        memory[i][nWish] = memory[i+1][nWish] + remove[diceOrg[i]];
    }

    for (int i = nWish-1; i >= 0; --i) {
        memory[nOrg][i] = memory[nOrg][i+1] + add[diceWish[i]];
    }

    for (int curOrg = nOrg-1; curOrg >= 0; --curOrg) {
        for (int curWish = nWish-1; curWish >= 0; --curWish) {
            int removeCurOrg =  memory[curOrg+1][curWish] + remove[diceOrg[curOrg]];
            int addCurWish = memory[curOrg][curWish+1] + add[diceWish[curWish]];
            int changeCurRealToCurWish = memory[curOrg+1][curWish+1] + turnDistance[diceOrg[curOrg]][diceWish[curWish]];

            memory[curOrg][curWish] = min({removeCurOrg, addCurWish, changeCurRealToCurWish});
        }
    }

    cout << memory[0][0];
}