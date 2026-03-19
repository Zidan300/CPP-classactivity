#include <iostream>
using namespace std;

int doubleFactorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * doubleFactorial(n - 2);
}

int main() {
    cout << "n       n!!" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i <= 10; i++) {
        cout << i << "       " << doubleFactorial(i) << endl;
    }

    return 0;
}
