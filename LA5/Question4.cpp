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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    return prev;
    }
};

int main() {

    return 0;
}