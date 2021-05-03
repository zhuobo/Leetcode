#include "structure.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int       curr_sum;
        int       carry = 0;
        while ( l1 != nullptr || l2 != nullptr || carry != 0 ) {
            if ( l1 != nullptr ) {
                curr_sum += l1->val;
                l1 = l1->next;
            }
            if ( l2 != nullptr ) {
                curr_sum += l2->val;
                l2 = l2->next;
            }
            curr_sum += carry;
            curr->next = new ListNode(curr_sum % 10);
            curr = curr->next;
            carry = curr_sum / 10;
            curr_sum = 0;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
