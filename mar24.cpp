#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }

    Node(int n) {
        data = n;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node *head;

    SinglyLinkedList() {
        head = NULL;
    }

    void insert(Node *n) {
        if (head == NULL) {
            head = n;
        } else {
            Node *cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = n;
        }
    }

    void display() {
        Node *cur = head;
        while (cur != NULL) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
    }

    Node* search(int elem, int *index) {
        *index = 0;
        Node *cur = head;

        while (cur != NULL) {
            if (cur->data == elem) {
                return cur;
            }
            (*index)++;
            cur = cur->next;
        }
        return NULL;
    }
};

int main() {
    Node n1(6);
    Node n2(10);
    Node n3(56);
    Node n4(88);
    Node n5(1);

    Node *found;
    int pos;

    SinglyLinkedList sll;

    sll.insert(&n1);
    sll.insert(&n2);
    sll.insert(&n3);
    sll.insert(&n4);
    sll.insert(&n5);

    sll.display();

    found = sll.search(1, &pos);

    if (found != NULL) {
        cout << endl << "Found element: " << found->data << " at position " << pos << endl;
    } else {
        cout << endl << "The searched element is not found." << endl;
    }

    return 0;
}
