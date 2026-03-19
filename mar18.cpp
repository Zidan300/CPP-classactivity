#include <iostream>
using namespace std;


void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i];
        if(i != size - 1) cout << ", "; 
    }
    cout << endl;
}


void insertionsort(int arr[], int size) {
    for(int ui = 1; ui < size; ui++) {  
        int j = ui;
        while(j > 0 && arr[j] < arr[j - 1]) {
    
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--; 
        }
    }
}

int main() {
    int arr[10] = {6, 9, 1, 3, 2, 10, 19, 88, 7, 2};
    
    cout << "Unsorted Array: " << endl;
    display(arr, 10);
    
    insertionsort(arr, 10);
    
    cout << "Sorted Array: " << endl;
    display(arr, 10);
    
    return 0;
}
