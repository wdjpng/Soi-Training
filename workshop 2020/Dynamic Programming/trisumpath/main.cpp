#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);
    for(int i = 0; i< n; i++){
        for (int j = 0; j < i+1; ++j) {
            int number;
            cin >> number;

            triangle[i].push_back(number);
        }
    }

    vector<vector<int>> parent(n-1);
    for (int h = 1; h < n; ++h) {
        for (int i = 0; i < triangle[h].size(); ++i) {
            int index1 = -1, index2 = -1;
            if(i > 0){
                index1 = triangle[h-1][i-1];
            }
            if(i < triangle[h-1].size()){
                index2 = triangle[h-1][i];
            }

            triangle[h][i] += max(index1, index2);
            if(index1 > index2){
                parent[h-1].push_back(i-1);
            } else{
                parent[h-1].push_back(i);
            }
        }
    }

    int max = -1;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if(triangle[n-1][i] > max){
            max = triangle[n-1][i];
            index = i;
        }
    }



    cout << max << "\n";
    string output = "";
    for (int i = 1; i < n; ++i) {
        if(parent[parent.size()-i][index] == index){
            output+="L";
        } else{
            output+="R";
            index--;
        }
    }

    reverse(output.begin(), output.end());
    cout << output << "\n";
}