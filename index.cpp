#include <iostream>
using namespace std;
int main(){

    int a;
    
    cout<<"enter the first term: ";
    cin >> a;
    
    int first = 0, second = 1;
    cout << "fibonacci series: ";

    for (int i = 0; i < a; i++) {
        cout << first << " " ;
        int  next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
    return 0;
}