#include <iostream>
using namespace std;

int findminindx(int start, int size, int arr[]) {
    int cur_idx = start;
    int cur_min_idx = cur_idx;

    for (int i = cur_idx + 1; i < size; i++) {
        if (arr[cur_min_idx] > arr[i]) {
            cur_min_idx = i;
        }
    }

    return cur_min_idx;
}

void selectionsort(int arr[], int size) {
    int min, temp;

    for (int i = 0; i < size - 1; i++) {
        min = findminindx(i, size, arr);

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubblesort(int arr[], int size){
    int temp;
    for(int i=0; i<size-1; i++){
       for(int j= i+1; j<size; j++){
           if(arr[i]>arr[j]){
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       } 
    }
}

void displayarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    int arr[10] = {3,6,7,2,20,54,1,19,99,5};

    bubblesort(arr, 10);
    displayarray(arr, 10);

    return 0;
}