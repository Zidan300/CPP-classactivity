#include <iostream>
using namespace std;
void printNumbers(int n) {
    if (n == 21)
    return;

    cout << n << " ";
    printNumbers(n+1);
}
int main(){
    printNumbers(0);
    return 0;
}