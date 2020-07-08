#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define int long long
using namespace std;

int fibonacci(int n, vector<int>& memory){
    if(memory[n] != -1){
        return memory[n];
    }

    return memory[n] = fibonacci(n-1, memory) + fibonacci(n-2, memory);
}
signed main() {
   int n;
   cin >> n;
   vector<int>memory(n+2, -1);
   memory[0] = 0;
   memory[1] = 1;

   cout << fibonacci(n, memory);
}