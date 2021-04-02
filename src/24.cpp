#include "structure.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        while ( head != nullptr ) {
            if ( head->next == nullptr ) {
                curr->next = head;
                break;
            } else {
                first = head;
                second = head->next;
                head = second->next;
                second->next = first;
                first->next = nullptr;
                curr->next = second;
                curr = first;
            }
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
