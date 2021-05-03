#include "structure.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for ( int i = 0; i < n + 1; ++i ) {
            fast = fast->next;
        } 
        while ( fast != nullptr ) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
