#include <iostream>
#include <vector>
#include <deque>
#include <limits>

#define int long long
using namespace std;

int containsDog(int i, int j, vector<vector<char>>& matrix){
    //Try catch not needed anymore, but they dont cause bugs
    int counter = 0;

    try {
        if(matrix[i][j] == 'D' && matrix[i][j +1 ] == 'O' && matrix[i][j + 2] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i][j -1 ] == 'O' && matrix[i][j - 2] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i + 1][j] == 'O' && matrix[i + 2][j] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i - 1][j] == 'O' && matrix[i - 2][j] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i + 1][j +1 ] == 'O' && matrix[i + 2][j + 2] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i - 1][j - 1 ] == 'O' && matrix[i - 2][j - 2] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i - 1][j +1 ] == 'O' && matrix[i - 2][j + 2] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    } 

    try {
        if(matrix[i][j] == 'D' && matrix[i + 1][j -1 ] == 'O' && matrix[i + 2][j - 2] == 'G'){
            counter++;
        }
    } catch (exception& e) {

    }
    return counter;
}
int dog(vector<vector<char>>& matrix){
    int counter = 0;

    if(matrix.size() < 7 && matrix[0].size() < 7){
        return  0;
    }

    for (int i = 2; i < matrix.size() - 2; ++i) {
        for (int j = 2; j < matrix[0].size() - 2; ++j) {
            counter+=containsDog(i,j, matrix);
            if(containsDog(i,j, matrix)){
                cout << containsDog(i,j, matrix);
            }
        }
    }

    return counter;
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> matrix (k+4, vector<char> (n+4, 'X'));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> matrix[i + 2][i + 2];
        }
    }

    cout << dog(matrix) << "\n";


}