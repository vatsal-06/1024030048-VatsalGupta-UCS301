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

static int idx = -1;
Node* buildTree(vector<int>& values) {
            idx++;

            if(values[idx] == -1) {
                return NULL;
            }

            Node* root = new Node(values[idx]);
            root->left = buildTree(values);
            root->right = buildTree(values);
            return root;
}

void preorderTrav(Node* root) {
    if(root == NULL) {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}

void inorderTrav(Node* root) {
    if(root == NULL) {
        return;
    }
    inorderTrav(root->left);
    cout << root->data << " ";
    inorderTrav(root->right);
}

void postorderTrav(Node* root) {
    if(root == NULL) {
        return;
    }
    postorderTrav(root->left);
    postorderTrav(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void levelOrderTrav(Node* root) {
     queue<Node*> q;

     q.push(root);

     while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
     }

     cout << endl;
 }

// Build from Preorder Inorder

int searchInorder(vector<int>& inorder, int inStart, int inEnd, int val) {
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

Node* preInBuildTree(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
    if (left > right) {
        return NULL;
    }
    Node* root = new Node(preorder[preIdx]);
    preIdx++;
    int inIdx = searchInorder(inorder, left, right, preorder[preIdx]);

    root->left = preInBuildTree(preorder, inorder, preIdx, left, inIdx - 1);
    root->right = preInBuildTree(preorder, inorder, preIdx, inIdx + 1, right);
    return root;
}

int main() {
    vector<int> values = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(values);
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;

    preorderTrav(root);
    cout << endl;
    inorderTrav(root);
    cout << endl;
    postorderTrav(root);
    cout << endl;
    levelOrderTrav(root);
    cout << endl;

    int preIdx = 0;
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder = {4, 2, 5, 1, 3};
    Node* newRoot = preInBuildTree(preorder, inorder, preIdx, 0, inorder.size() - 1);
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;

    return 0;
}
