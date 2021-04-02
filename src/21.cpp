#include "structure.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while ( l1 != nullptr && l2 != nullptr ) {
            if ( l1->val < l2->val ) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 == nullptr ? l2 : l1;
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
