#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int playlist[] = {101, 305, 202, 410, 150}; 
    int n = 5;
    int songID = 202;

    int result = sequentialSearch(playlist, n, songID);
    if(result != -1) 
        cout << "Song found at position: " << result << endl;
    else
        cout << "Song not found." << endl;

    return 0;
}
