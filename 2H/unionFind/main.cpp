#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

int find(int numberToFind, vector<int>& countries){
    if(numberToFind == countries[numberToFind]){
        return numberToFind;
    } else{
        return countries[numberToFind] = find(countries[numberToFind], countries);
    }
}

void printCountries(vector<int>& countries){
    for (int i = 1; i < countries.size(); i++) {
        cout << find(i, countries) << " ";
    }
    cout << "\n";
}

void unite(bool isModern, int a, int b, vector<int>& countries){
    int chefA = find(a, countries);
    int chefB = find(b, countries);

    if(isModern){
        if(chefA <= chefB){
            countries[chefB] = chefA;
        } else{
            countries[chefA] = chefB;
        }
    } else{
        countries[chefB] = chefA;
    }
}

void unionFind(bool isModern, int numberOfCountries, int numberOfLines){
    vector<int> countries(numberOfCountries + 1);


    
    for(int i = 1; i <= numberOfCountries; i++){
        countries[i] = i;
    }

    for(int column = 0; column < numberOfLines; column++){
        int action;

        cin >> action;

        if(action == -1){
            printCountries(countries);
        } else{
            int secondNumber;

            cin >> secondNumber;

            unite(isModern,action, secondNumber, countries);
        }
    }
}

signed main() {
    bool isModern;
    int numberOfCountries, numberOfLines;

    cin >> isModern >> numberOfCountries >> numberOfLines;

    unionFind(isModern, numberOfCountries, numberOfLines);
}