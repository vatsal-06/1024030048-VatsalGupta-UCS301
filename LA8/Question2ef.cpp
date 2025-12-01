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

int main() {
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    Node* root = buildBST(values);

    return 0;
}