#include <iostream>
using namespace std;

int main() {
    string students[] = {"ram", "shayam", "hari", "sita", "gita"};
    int n = 5;
    string searchName;
    bool found = false;

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
