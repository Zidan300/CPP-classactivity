#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int num) {
        data = num;
        next = NULL;
    }
};

class SLL {
public:
    Node *head;

    SLL() {
        head = NULL;
    }

    void insert(Node *n1) {
        if (head == NULL) {
            head = n1;
        } else {
            Node *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = n1;
        }
    }

    void insertfirst(Node *n1) {
        n1->next = head;
        head = n1;
    }

    void insertafter(Node *prev, Node *n1) {
        if (prev == NULL) {
            cout << "Previous node cannot be NULL" << endl;
            return;
        }
        n1->next = prev->next;
        prev->next = n1;
    }

    void display() {
        Node *ptr = head;
        while (ptr != NULL) {
            cout << "|" << ptr->data << "|" << " --> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Node n1(9);
    Node n2(56);
    Node n3(23);
    Node n4(39);
    Node n5(99);

    SLL s;

    s.insert(&n1);
    s.display();

    s.insert(&n2);
    s.display();

    s.insert(&n3);
    s.display();

    s.insertfirst(&n4);
    s.display();

    s.insertafter(&n2, &n5);
    s.display();

    return 0;
}
