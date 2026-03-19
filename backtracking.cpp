#include <iostream>
#include <vector>
using namespace std;


void generateSubsets(vector<int>& subset, vector<int>& arr, int index) {
    if(index == arr.size()) {
        cout << "{ ";
        for(int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if(i != subset.size() - 1) cout << ", ";
        }
        cout << " }" << endl;
        return;
    }

    subset.push_back(arr[index]);
    generateSubsets(subset, arr, index + 1);
    subset.pop_back();
    generateSubsets(subset, arr, index + 1);
}

int main() {
    int n, value;
    vector<int> arr, subset;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        arr.push_back(value);
    }
    cout << "\nAll subsets of the given set are:\n";
    generateSubsets(subset, arr, 0);

    return 0;
}