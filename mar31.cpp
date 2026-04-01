#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int num) {
        prev = nullptr;
        next = nullptr;
        data = num;
    }
};

class Dll {
public:
    Node* head;
    Node* tail;

    Dll() {
        head = nullptr;
        tail = nullptr;
    }

    void insertatend(Node* n) {
        if (head == nullptr && tail == nullptr) {
            head = n;
            tail = n;
        } else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    void display() {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << "|" << ptr->data << "| <-->";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }

    void displayreverse() {
        Node* ptr = tail;
        while (ptr != nullptr) {
            cout << "|" << ptr->data << "| <-->";
            ptr = ptr->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Node n1(5);
    Node n2(9);
    Node n3(7);
    Node n4(99);
    Node n5(88);

    Dll d;
    d.insertatend(&n1);
    d.display();
    d.insertatend(&n2);
    d.display();
    d.insertatend(&n3);
    d.display();
    d.insertatend(&n4);
    d.display();
    d.insertatend(&n5);
    d.display();
    d.displayreverse();

    return 0;
}
