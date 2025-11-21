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

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int val) {
            data = val;
            next = NULL;
        }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp->next != NULL) {
            if (temp->next->data == val) {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};

int main() {

    return 0;
}