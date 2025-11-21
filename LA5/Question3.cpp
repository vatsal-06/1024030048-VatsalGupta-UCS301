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
    ListNode* middleNode(ListNode* head) {
        ListNode* sp = head;
        ListNode* fp = head;

        while(fp != NULL && fp->next != NULL) {
            sp = sp->next;
            fp = fp->next->next;
        }
        return sp;
    }
};

int main() {

    

    return 0;
}