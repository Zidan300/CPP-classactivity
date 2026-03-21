#include <iostream>
using namespace std;

int main() {
    long long m, n, k = 0;

    // Input: two positive integers m and n (both > 1)
    cout << "Enter m and n (both > 1): ";
    cin >> m >> n;

    // Compute the largest power of n that divides m
    while (m % n == 0) {
        m /= n;
        k++;
    }

    cout << "The largest power of " << n << " that divides " << m << " is " << k << endl;

    return 0;
}


