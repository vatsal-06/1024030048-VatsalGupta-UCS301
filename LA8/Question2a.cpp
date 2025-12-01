#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
};

Node* insertBST(Node* root, int value) {
    if(root == NULL) {
        return new Node(value);
    }

    if(value < root->data) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }

    return root;
}

Node* buildBST(vector<int>& values) {
    Node* root = NULL;

    for(int val : values) {
        root = insertBST(root, val);
    }

    return root;
}

bool searchBSTRecursion(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) {
        return searchBSTRecursion(root->left, key);
    } else {
        return searchBSTRecursion(root->right, key);
    }

    return false;
}

Node* searchBSTNonRecusion(Node* root, int key) {
    Node* current = root;

    while(current != NULL) {
        if(current->data == key) {
            return current;
        } else if(key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

int main() {
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    Node* root = buildBST(values);

    cout << searchBSTRecursion(root, 3) << endl; // Output: 1
    cout << searchBSTRecursion(root, 10) << endl; // Output: 0 

    cout << searchBSTNonRecusion(root, 4)->data << endl; // Output: 4
    cout << searchBSTNonRecusion(root, 10) << endl; // Output: 1

    return 0;
}