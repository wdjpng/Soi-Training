#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>

#define int long long
using namespace std;



signed main() {
    int n, m, k;
    cin >> n >> m >> k;

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string message;
    cin >> message;

    vector<string>possiblyEncodings(m+1, "");
    vector<int>encodings(1024, -1);
    for (int i = 0; i < k; ++i) {
        string code;
        cin >> code;
        int sum = 1;
        for (int j = 0; j < code.size(); ++j) {
            sum*=2;
            if(code[j] == '1'){
                sum++;
            }
        }
        encodings[sum]=i;
    }

    for (int i = m-1; i >= 0; i--) {
        string possible = "not decodable";
        int curSum = 1;
        for (int j = i; j <= min(m-1, i+8); ++j) {
            curSum*=2;
            if(message[j]=='1'){
                curSum++;
            }
            if(encodings[curSum] != -1){
                if(possible != "not decodable" || (j != m-1 && possiblyEncodings[j+1] == "not uniquely decodable")){
                    possible="not uniquely decodable";
                    break;
                } else
                if(j == m-1 ||  possiblyEncodings[j+1] != "not decodable"){
                    possible = encodings[curSum] + 'A';
                    if(j != m-1){
                        possible+=possiblyEncodings[j+1];
                    }
                }
            }

        }
        possiblyEncodings[i]=possible;
    }

    cout <<  possiblyEncodings[0] << "\n";
}