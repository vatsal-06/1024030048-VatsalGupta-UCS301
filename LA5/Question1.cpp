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

class List {
    Node* head;
    Node* tail;

    public:
        List() {
            head = tail = NULL;
        }

        void pushFront(int val) {
            Node* newNode = new Node(val);
            if(head == NULL) {
                head = tail = newNode;
                return;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void pushBack(int val) {
            Node* newNode = new Node(val);
            if(head == NULL) {
                head = tail = newNode;
                return;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void popFront() {
            if(head == NULL) {
                cout << "LL is empty";
                return;
            }
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        void popBack() {
            if(head == NULL) {
                cout << "LL is Empty";
                return;
            }
            Node* temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void insert(int val, int pos) {
            if(pos < 0) {
                cout << "Invalid Position\n";
                return;
            } 
            if(pos == 0) {
                pushFront(val);
                return;
            }

            Node* temp = head;
            for(int i = 0; i < pos - 1; i++) {
                if(temp == NULL) {
                    cout << "Invalid Position\n";
                }
                temp = temp->next;
            }

            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void display() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        int search(int key) {
            Node* temp = head;
            int idx = 0;

            while(temp != NULL) {
                if(temp->data == key) {
                    return idx;
                }
                temp = temp->next;
                idx++;
            }
            return -1;
        }
};

int main() {
    List ll;

    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);

    ll.insert(4, 1);

    ll.display();

    cout << ll.search(2) << endl;

    return 0;
}
