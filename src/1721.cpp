#include "structure.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* first = nullptr;
        for ( int i = 0; i < k; ++i ) {
            if ( i == k - 1 ) {
                first = fast;
            }
            fast = fast->next;
        }
        while ( fast != nullptr ) {
            fast = fast->next;
            slow = slow->next;
        }
        int temp = first->val;
        first->val = slow->val;
        slow->val = temp;
        return head;
    }
};
