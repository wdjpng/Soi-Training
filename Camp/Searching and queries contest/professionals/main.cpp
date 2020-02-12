#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define int long long
using namespace std;


bool isPossible(deque<int> vector, int n, int hours) {
    int currentSize=0;
    int counter = 1;
    while(vector.size()!=0){
        int cur = vector.front();
        vector.pop_front();

        currentSize+= cur;

        if(currentSize > hours){
            currentSize=cur;
            counter++;
        }
    }
    return n >= counter;
}

int lawFirm(deque<int> times, int n, int k){
    int max = -1;
    int sum = 0;
    for (int i = 0; i < times.size(); ++i) {
        if(times[i] > max){
            max = times[i];
        }
        sum+=times[i];
    }

    int start = max;
    int end = sum;

    while (start +1< end){
        int cur = (start+end)/2;

        if(isPossible(times, n, cur)){
            end = cur;
        } else{
            start = cur;
        }
    }

    if(isPossible(times, n, start)){
        return start;
    } else{
        return end;
    }
}

signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int n, q;
    cin >> n;

    vector<int>input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        input[i]=input[i]-i-1;
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int overtakenAmateurs;
        cin >> overtakenAmateurs;

        vector<int>::iterator lower = lower_bound (input.begin(), input.end(), overtakenAmateurs);

        if(lower == input.end() || input[lower-input.begin()] != overtakenAmateurs){
            cout << "-1\n";
        } else{
            cout << lower-input.begin()+1 << "\n";
        }
    }
}