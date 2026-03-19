#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Print tree with arrows
void printTree(Node* root, string prefix = "", bool isLeft = true) {
    if (root == nullptr) return;

    if (root->right)
        printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);

    cout << prefix;
    cout << (isLeft ? "└── " : "┌── ");
    cout << root->data << endl;

    if (root->left)
        printTree(root->left, prefix + (isLeft ? "    " : "│   "), true);
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);


    printTree(root);

    return 0;
}