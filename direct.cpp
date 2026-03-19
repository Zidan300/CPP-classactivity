

#include <iostream>
using namespace std;

int squareB(int n);
int n;

int squareA(int n){
    if (n == 0){
        return 0;
    }
    return squareB(n - 1) + (2 * n - 1);
}

int squareB(int n){
    return squareA(n);
}

int main() {
    cout << "enter a number: ";
   cin >> n;
    cout << "square of " << n << " is: " << squareA(n);
    return 0;
}
