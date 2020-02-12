#include <iostream>
#include <vector>
#include <deque>

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
    int n, k;
    cin >> n >> k;

    deque<int> effeciency(k);
    for(int i = 0; i< k; i++){
        cin >> effeciency[i];
    }

    cout << lawFirm(effeciency, n, k) << "\n";
}