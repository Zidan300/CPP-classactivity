#include <iostream>
using namespace std;

int main(){
	int num1;
	int num2;
	char operation;
	int result;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	cout << "Choose the operation(*,+,-,/): ";
	cin >> operation;

	if (operation =='*'){
		result = num1 * num2;
	}else if( operation == '+'){
		result = num1 + num2;
	}else if( operation == '-'){
		result = num1 - num2;
	}else if( operation == '/'){
	if (num2 !=0){
	result = num1 / num2;
	}else{
	cout << "cannot divide by zero" << endl;
	return 0;
	}
	cout << "The result is:" << result << endl;
	return 0;
}
}
