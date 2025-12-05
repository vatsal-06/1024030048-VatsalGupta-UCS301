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
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void makeCircular() {
        if (tail != NULL)
            tail->next = head;
    }

    void splitCircular(Node*& head1, Node*& head2) {
        if (head == NULL || head->next == head) {
            head1 = head;
            head2 = NULL;
            return;
        }

        Node* sp = head;
        Node* fp = head;

        while (fp->next != head && fp->next->next != head) {
            sp = sp->next;
            fp = fp->next->next;
        }

        head1 = head;
        head2 = sp->next;

        sp->next = head1;

        if (fp->next->next == head)
            fp = fp->next;

        fp->next = head2;
    }

    void displayCircular(Node* h) {
        if (h == NULL) {
            cout << endl;
            return;
        }

        Node* temp = h;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != h);
        cout << endl;
    }
};

int main() {
    List lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(4);
    lst.pushBack(5);

    lst.makeCircular();

    Node* head1 = NULL;
    Node* head2 = NULL;

    lst.splitCircular(head1, head2);

    lst.displayCircular(head1);
    lst.displayCircular(head2);

    return 0;
}
