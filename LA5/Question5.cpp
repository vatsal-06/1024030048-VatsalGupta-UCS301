#include <iostream>
using namespace std;

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }

        ListNode* sp = head;
        ListNode* fp = head;

        while(fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;

            if(sp == fp) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}