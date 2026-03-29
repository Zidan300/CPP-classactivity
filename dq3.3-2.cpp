#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int playlist[] = {101, 150, 202, 305, 410}; 
    int n = 5;
    int songID = 202;

    int result = binarySearch(playlist, n, songID);
    if(result != -1)
        cout << "Song found at position: " << result << endl;
    else
        cout << "Song not found." << endl;

    return 0;
}
