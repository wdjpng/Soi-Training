#include <bits/stdc++.h>

#define int long long
using namespace std;

//I am aware that this is a bit ugly

int getCrossSum(int a){
    if(a<1){
        return 0;
    }


    vector<int>memory(18,0);
    memory[0]=45;
    int power = 10;
    for (int i = 1; i < memory.size(); ++i) {
        for (int curDigit = 0; curDigit < 10; ++curDigit) {
            memory[i]+=curDigit*power+memory[i-1];
        }
        power*=10;
    }

    int mod = 1;
    int counter = 0;
    while (mod*10 <= a){
        mod*=10;
        counter++;
    }

    int sum=0;
    for (int curCounter = counter; curCounter >= 0; --curCounter) {
        int digit = a-a%mod;
        while (digit>9){
            digit/=10;
        }

        for (int curDigit = 0; curDigit < digit; ++curDigit) {
            sum+=curDigit*mod;

            if(curCounter>0){
                sum+=memory[curCounter-1];
            }
        }

        if(curCounter != 0){
            sum+=digit*(a%mod+1);
        } else{
            sum+=digit;
        }

        a-=digit*mod;
        mod/=10;
    }

    return sum;
}
signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int a,b;
    cin >> a >> b;
    
    cout << getCrossSum(b) - getCrossSum(a-1);
}