#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

// Function to check palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* left = head;
    Node* right = head;

    // move right to last node
    while (right->next != NULL)
        right = right->next;

    // compare from both ends
    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

// Utility function to create a node
Node* createNode(char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insertEnd(Node* head, char c) {
    Node* newNode = createNode(c);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

int main() {
    Node* head = NULL;

    // Example: "level"
    head = insertEnd(head, 'l');
    head = insertEnd(head, 'e');
    head = insertEnd(head, 'v');
    head = insertEnd(head, 'e');
    head = insertEnd(head, 'l');

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
