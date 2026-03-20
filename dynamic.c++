#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    string line;
    int value;

    cout << "Enter numbers separated by spaces: ";
    getline(cin, line); 

    stringstream ss(line);
    while (ss >> value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = tail = newNode; 
        } else {
            tail->next = newNode; 
            tail = newNode;
        }
    }
    cout << "Linked list: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}