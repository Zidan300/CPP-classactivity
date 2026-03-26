#include<iostream>
using namespace std;

int main() {
    int arr[16] = {5, 9, 11, 17, 18, 32, 45, 67, 77, 98, 111, 123, 145, 167, 178, 189};
    int searchfor = 145;

    int low_index = 0;
    int high_index = 15;
    int mid_index;

    while (low_index <= high_index) {
        mid_index = (low_index + high_index) / 2;

        if (arr[mid_index] == searchfor) {
            cout << "Item found at index: " << mid_index << endl;
            return 0;
        }
        else if (searchfor > arr[mid_index]) {
            low_index = mid_index + 1;
        }
        else {
            high_index = mid_index - 1;
        }
    }

    cout << "CANNOT FIND ITEM..." << endl;
    return 0;
}
