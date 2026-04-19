#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int values[] = {15, 10, 20, 8, 12, 16, 25};
    Node* root = NULL;

    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    cout << "Pre-order Traversal: ";
    preorder(root);

    return 0;
}
