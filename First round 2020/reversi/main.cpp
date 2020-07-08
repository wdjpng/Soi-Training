#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;
#define int long long

ifstream fin("/tmp/reversi-sub3-attempt2.txt");
#define cin fin

signed main() {
    int testCases;
    cin >> testCases;
    ofstream out("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    for (int i = 0; i < testCases; ++i) {
        string input;
        //Incredibly nice coding to get rid of the n
        cin >> input >> input;

        int start = 0;
        int end = input.size()-1;
        char lastStartChar = input[0];
        char lastEndChar = input[input.size()-1];
        int counter = 0;
        int startPlus = 0;
        int endPlus = 0;
        bool startFlag = false, endFlag = false;
        while (true) {
            if(!startFlag){
                start++;

                if(input[start] != lastStartChar){
                    counter += start + 1 + startPlus;
                    startPlus++;
                    startFlag = true;
                }
            } else{
                startFlag = false;
            }

            if(start == end){
                break;
            }
            if(!endFlag){
                end--;
                if(input[end] != lastEndChar){
                    counter += input.size() - end + endPlus;
                    endPlus++;
                    endFlag = true;
                }
            } else{
                endFlag = false;
            }
            if(start == end){
                break;
            }

            lastStartChar = input[start];
            lastEndChar = input[end];
        }
        cout << "Case #" << i << ": " << counter << "\n";

    }
}