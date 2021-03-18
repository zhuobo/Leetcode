#include "structure.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for ( int i = 1; i < left; ++i ) {
            curr->next = head;
            head = head->next;
            curr = curr->next;
        }
        ListNode* head_next = nullptr;
        ListNode* curr_next = nullptr;
        ListNode* end       = nullptr;
        curr->next = head;
        head = head->next;
        end = curr->next;
        for ( int i = left; i < right; ++i ) {
            curr_next = curr->next;
            head_next = head->next;
            curr->next = head;
            head->next = curr_next;
            head = head_next;
        }
        end->next = head;
        return dummy->next;
    }
};
