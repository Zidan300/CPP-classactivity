#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    string students[n];
    string searchName;
    bool found = false;

    cout << "Enter student names:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, students[i]);
    }

    cout << "Enter student name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < n; i++) {
        if (students[i] == searchName) {
            cout << searchName << " was present at position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << searchName << " was not present in the class" << endl;
    }

    return 0;
}
