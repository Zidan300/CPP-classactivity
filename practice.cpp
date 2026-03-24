#include <iostream>
#include <string>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    double num1, num2, result;
    char op;

    // Initialize the calculator
    cout << "Welcome to the accurate calculator!" << endl;

    // Get user input for the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Check if the input is a valid number
    if (!std::istringstream(num1) || !(num1 > 0)) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Get user input for the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Check if the input is a valid number
    if (!std::istringstream(num2) || !(num2 > 0)) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Get user input for the operator (+, -, \*, /)
    cout << "Enter the operator (+, -, \*, /): ";
    cin >> op;

    // Check if the input is a valid operator
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        cout << "Invalid operator!" << endl;
        return 1;
    }

    // Perform the calculation
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        cout << "Invalid operator!" << endl;
        return 1;
    }

    // Format the result with precision and scale
    fixed (double &result, int precision) {
        result = std::fixed(result, precision);
    }

    // Print the result
    cout << "Result: " << result << endl;

    return 0;
}
