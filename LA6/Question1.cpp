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

class CircularLinkedList {
    private:
        Node* head;

    public:
        CircularLinkedList() {
            head = NULL;
        }

        void insertHead(int val) {
            Node* newNode = new Node(val);
            if(!head) {
                head = newNode;
                newNode->next = head;
            } else {
                Node* temp = head;
                while(temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
                head = newNode;
            }
        }

        void insertTail(int val) {
            Node* newNode = new Node(val);
            if(!head) {
                head = newNode;
                newNode->next = head;
            } else {
                Node* temp = head;
                while(temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
            }
        }

        void insertAtPosition(int val, int pos) {
            if(pos == 0) {
                insertHead(val);
                return;
            }
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i = 0; i < pos - 1; i++) {
                if(temp->next == head) break;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteNode(int val) {
            if(!head) return;
            if(head->data == val) {
                if(head->next == head) {
                    delete head;
                    head = NULL;
                } else {
                    Node* temp = head;
                    while(temp->next != head) {
                        temp = temp->next;
                        if(temp->next == head) break;
                        if(temp->next->data == val) {
                            Node* toDelete = temp->next;
                            temp->next = toDelete->next;
                            if(toDelete == head) head = toDelete->next;
                            delete toDelete;
                    }
                }
            }
        }
    }

    void search(int val) {
        if(!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            if(temp->data == val) {
                cout << "Value " << val << " found in the list." << endl;
                return;
            }
            temp = temp->next;
            } while(temp != head);
        cout << "Value " << val << " not found in the list." << endl;
    } 

    void display() {
        if (!head) return;
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
    }
};

int main() {

    return 0;
}