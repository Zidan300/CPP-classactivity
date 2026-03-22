#include <iostream>
using namespace std;

int main() {
    int num1, num2, result;
    char op;

    // Prompt the user for input
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Choose the operation (*, +, %, -): ";
    cin >> op;

    // Perform the selected operation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2; // Integer division
    } else if (op == '%') {
        result = num1 % num2; // Remainder
    } else {
        cout << "Invalid operator!" << endl;
        return 1; // Exit with error code
    }

    // Display the result
    cout << "Result: " << result << endl;
    return 0;
}
