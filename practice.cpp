#include <iostream>

using namespace std;

int main() {
    int num1, num2, sum;
    char operatorChoose;

    // Get input from user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Prompt user to choose an operator (+, -, x, /)
    cout << "Choose an operator: ";
   cin >> operatorChoose;

    // Perform calculation based on user's input
    if (operatorChoose == '+') {
        sum = num1 + num2;
    } else if (operatorChoose == '-') {
        sum = num1 - num2;
    } else if (operatorChoose == '*') {
        sum = num1 * num2;
    } else if (operatorChoose == '/') {
        sum = num1 / num2;
    }

    // Print result to the screen
    cout << "Result: ";
    cout << sum << endl;

    return 0;
}
