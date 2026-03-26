#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int data[] = {1, 3, 5, 7, 9};
    int n = 5;

    cout << linearSearch(data, n, 7); 
    return 0;
}
