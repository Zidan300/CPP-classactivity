#include <iostream>
using namespace std;

int factorialA(int n);
int factorialB(int n);

int factorialA(int n) {
    if (n <= 1)
        return 1; // Base case
    return n * factorialB(n - 1); 
}
int factorialB(int n) {
    return factorialA(n); 
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Factorial of " << num << " is " << factorialA(num) << endl;
    return 0;
}
