#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

#define int long long
using namespace std;


signed main() {
    string input;
    cin >> input;

    stack<char> history;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
            history.push(input[i]);
        } else if (history.size() == 0) {
            cout << "imbalanced\n";
            exit(0);
        } else if (input[i] == '}') {
            if (history.top() != '{') {
                cout << "imbalanced\n";
                exit(0);
            }
            history.pop();
        } else if (input[i] == ']') {
            if (history.top() != '[') {
                cout << "imbalanced\n";
                exit(0);
            }
            history.pop();
        } else if (history.top() != '(') {
            cout << "imbalanced\n";
            exit(0);
        } else {

            history.pop();
        }
    }

    if(history.size() == 0){cout << "balanced\n";} else{
        cout << "imbalanced\n";
    }
}