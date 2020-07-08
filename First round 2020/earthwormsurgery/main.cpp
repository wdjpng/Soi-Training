using namespace std;


#include <iostream>
#include <stdint.h>
#include <bits/stdc++.h>
ifstream fin("/tmp/earthwormsurgery-sub2-attempt4.txt");
#define cin fin
string middlePartOnes = "", middlePartZeros = "";

void dropColor(int index, string& worm){
    string startPart, middlePart, endPart = "";
    startPart = "";
    middlePart = "";
    endPart = "";

    if(worm[index] == '0'){
        middlePart = middlePartOnes;
    } else{
        middlePart = middlePartZeros;
    }

    if(index > 0){
        startPart = worm.substr(0, index );
    }

    if(index + 1 < worm.size()){
        endPart = worm.substr(index+1, worm.size() - 1);
    }

    worm = startPart + middlePart + endPart;
}
signed main() {
    int testCases;
    cin >> testCases;
    ofstream out("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    for (int testCase = 0; testCase < testCases; ++testCase) {
        middlePartOnes="";
        middlePartZeros="";

        int n, m, dropSize, cutSize;
        cin >> n >> m >> dropSize >> cutSize;

        string desiredPattern, currentPattern;
        cin >> currentPattern >> desiredPattern;

        if(dropSize==1){
            if(desiredPattern.size() == currentPattern.size()){
                cout << "Case #" << testCase << ": YES\n";
            } else{
                cout << "Case #" << testCase << ": NO\n";
            }
            continue;
        }
        for (int j = 0; j < dropSize; ++j) {
            middlePartZeros+='0';
            middlePartOnes+='1';
        }
        while(currentPattern.size() < desiredPattern.size()){
            dropColor(0, currentPattern);
        }

        for (int i = 0; i < desiredPattern.size(); ++i) {
            if(currentPattern[i] != desiredPattern[i]){
                dropColor(i, currentPattern);
            }
        }

        int zeros, ones;
        zeros = 0;
        ones = 0;
        currentPattern = currentPattern.substr(desiredPattern.size(), currentPattern.size()-1);

        for (int i = 0; i < currentPattern.size(); ++i) {
            if(currentPattern[i] == '0'){
                zeros++;
            } else{
                ones++;
            }
        }

        zeros+=ones*dropSize;
        vector<bool> hasAppeared(cutSize*2, false);
        int cur = zeros%(cutSize*2);
        while (!hasAppeared[cur]){
            hasAppeared[cur] = true;

            cur = (cur * dropSize) % (cutSize*2);
        }

        if(hasAppeared[0] || hasAppeared[cutSize]){
            cout << "Case #" << testCase << ": YES\n";
        } else{
            cout << "Case #" << testCase << ": NO\n";
        }
    }
}
