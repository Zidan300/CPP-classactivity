#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

// =============================================
// 1. Hash Table with Chaining
// =============================================
class ChainingHashTable {
private:
    vector<list<int>> table;
    int tableSize;

public:
    ChainingHashTable(int size = 10) : tableSize(size), table(size) {}

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hashFunction(key);
        // Do not allow duplicates
        if (find(table[index].begin(), table[index].end(), key) == table[index].end()) {
            table[index].push_back(key);
        }
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);
        if (it != table[index].end()) {
            table[index].erase(it);
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        return find(table[index].begin(), table[index].end(), key) != table[index].end();
    }

    void display() {
        cout << "Chaining Hash Table (buckets 0-" << tableSize-1 << "):" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL" << endl;
        }
        cout << endl;
    }
};

// =============================================
// 2. Linear Probing (Open Addressing)
// =============================================
class LinearProbingHashTable {
private:
    vector<int> table;
    int tableSize;

public:
    LinearProbingHashTable(int size = 10) : tableSize(size), table(size, -1) {}  // -1 means empty

    int h1(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        // Check for duplicate first
        if (search(key)) return;

        int index = h1(key);
        int i = 0;
        while (table[(index + i) % tableSize] != -1) {
            i++;
            if (i >= tableSize) {
                cout << "Linear Probing: Table is full! Could not insert " << key << endl;
                return;
            }
        }
        table[(index + i) % tableSize] = key;
    }

    bool search(int key) {
        int index = h1(key);
        for (int i = 0; i < tableSize; i++) {
            int pos = (index + i) % tableSize;
            if (table[pos] == -1) return false;
            if (table[pos] == key) return true;
        }
        return false;
    }

    void display() {
        cout << "Linear Probing Hash Table:" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": " << (table[i] == -1 ? "empty" : to_string(table[i])) << endl;
        }
        cout << endl;
    }
};

// =============================================
// 3. Double Hashing (Open Addressing)
// =============================================
class DoubleHashingHashTable {
private:
    vector<int> table;
    int tableSize;

public:
    DoubleHashingHashTable(int size = 10) : tableSize(size), table(size, -1) {}

    int h1(int key) {
        return key % tableSize;
    }

    int h2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        // Check for duplicate first
        if (search(key)) return;

        int index = h1(key);
        int step = h2(key);
        int i = 0;
        while (table[(index + i * step) % tableSize] != -1) {
            i++;
            if (i >= tableSize) {
                cout << "Double Hashing: Table is full! Could not insert " << key << endl;
                return;
            }
        }
        table[(index + i * step) % tableSize] = key;
    }

    bool search(int key) {
        int index = h1(key);
        int step = h2(key);
        for (int i = 0; i < tableSize; i++) {
            int pos = (index + i * step) % tableSize;
            if (table[pos] == -1) return false;
            if (table[pos] == key) return true;
        }
        return false;
    }

    void display() {
        cout << "Double Hashing Hash Table:" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": " << (table[i] == -1 ? "empty" : to_string(table[i])) << endl;
        }
        cout << endl;
    }
};

// =============================================
// Main function to demonstrate everything
// =============================================
int main() {
    cout << "=== HASH TABLE DEMONSTRATION ===" << endl << endl;

    // Chaining demonstration
    cout << "1. CHAINING HASH TABLE" << endl;
    ChainingHashTable cht;
    cht.insert(10);
    cht.insert(20);
    cht.insert(30);  // collision with 10 & 20 (all hash to 0)
    cht.insert(5);
    cht.insert(15);  // collision with 5 (hash to 5)
    cht.insert(10);  // duplicate - should be ignored
    cout << "After insertions (showing collisions resolved by chaining):" << endl;
    cht.display();

    cout << "Search for 20: " << (cht.search(20) ? "Found" : "Not found") << endl;
    cht.remove(20);
    cout << "After deleting 20:" << endl;
    cht.display();

    // Linear Probing demonstration
    cout << "2. LINEAR PROBING" << endl;
    LinearProbingHashTable lpt;
    lpt.insert(10);
    lpt.insert(20);
    lpt.insert(30);  // collision -> probes forward
    lpt.insert(0);   // another collision at index 0
    lpt.insert(10);  // duplicate - ignored
    cout << "After insertions (showing linear probing collision resolution):" << endl;
    lpt.display();

    // Double Hashing demonstration
    cout << "3. DOUBLE HASHING" << endl;
    DoubleHashingHashTable dht;
    dht.insert(10);
    dht.insert(20);
    dht.insert(30);
    dht.insert(0);
    dht.insert(10);  // duplicate - ignored
    cout << "After insertions (showing double hashing collision resolution):" << endl;
    dht.display();

    cout << "=== END OF DEMONSTRATION ===" << endl;
    return 0;
}
