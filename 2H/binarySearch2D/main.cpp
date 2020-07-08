#include <bits/stdc++.h>

#define int long long

using namespace std;

int currentNumberOfGuesses = 0;


//This is an implementation of improved binary partition
void binary_search_2D(int & numberOfGuesses, int& width, int& height, int currentX, int currentY) {
    if(currentNumberOfGuesses == numberOfGuesses || currentX >= width || currentY >= height){
        cout << "no solution\n";
        exit(0);
    }

    int currentNumber;
    cout << "q " << currentX << " " << currentY << "\n";
    cin >> currentNumber;

    if(currentNumber == 1337){
        cout << "s " << currentX << " " << currentY << "\n";
        exit(0);
    }

    else if (currentNumber > 1337){
        currentX += 1;
    } else{
        currentY += 1;
    }

    currentNumberOfGuesses+=1;
    binary_search_2D(numberOfGuesses, width, height, currentX, currentY);
}

//This is an implementation of improved binary partition
void binary_search_1D(int & numberOfGuesses, int& width, int& height) {



    bool isWidth1 = width == 1;

    int start = 0;
    int end = 0;
    if(isWidth1){
         start=height-1;
    } else{
        end=width-1;
    }


    while(currentNumberOfGuesses < numberOfGuesses){
        int currentNumber;
        if(isWidth1){
            cout << "q " << 0 << " " << (start+end)/2 << "\n";
        } else{
            cout << "q " << (start+end)/2 << " " << 0 << "\n";
        }

        cin >> currentNumber;

        if(currentNumber == 1337){
            if(isWidth1){
                cout << "s " << 0 << " " << (start+end)/2 << "\n";
            } else{
                cout << "s " << (start+end)/2 << " " << 0 << "\n";
            }
            exit(0);
        }

        else if (currentNumber > 1337){
            if(isWidth1){
                end = (start+end)/2;
            } else{
                start = (start+end)/2;
            }
        } else{
            if(isWidth1){
                start = (start+end)/2;
            } else{
                end = (start+end)/2;
            }
        }

        currentNumberOfGuesses+=1;
    }

    cout << "no solution";
}

signed main() {
    int width, height, numberOfGuesses;

    cin >> width >> height >> numberOfGuesses;

    if(width == 1 || height == 1){
        binary_search_1D(numberOfGuesses, width, height);
    }
    else{
        binary_search_2D(numberOfGuesses, width, height, 0,  0);
    }


}