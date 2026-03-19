#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int m = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n; j > 0; j--) {
            for (int k = 0; k < 10; k++) {
                m = m + 2;
            }
        }
    }

    cout << m << endl;
    return 0;
}
