#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

int sizeOfDoublyLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int sizeOfCircularLinkedList(Node* head) {
    if (head == NULL)
        return 0;

    int count = 1;
    Node* temp = head->next;

    while (temp != head) {
        count++;
        temp = temp->next;
    }

    return count;
}


int main() {

    return 0;
}