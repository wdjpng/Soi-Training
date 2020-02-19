#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <math.h>
#include <algorithm>

#define int unsigned long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

   int n, k;
   cin >> k >> n;
   if(k >= pow(2, n)){
       cout << "No solution\n";
       exit(0);
   }

   int subtractor = 1;
   int counter = 0;
   while (k%subtractor == 0){
       subtractor*=2;
       counter++;
   }

   cout << counter << "\n";
}