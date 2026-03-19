#include <iostream>
using namespace std;

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = 5;

  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    swap(arr[i], arr[min_idx]);
  }

  cout << "Selection Sort Result: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}