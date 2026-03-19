#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int arr[] = {5, 9, 8, 2, 6};
  int n = 5;

  sort(arr, arr + n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}