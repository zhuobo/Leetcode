#include "structure.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr1 = dummy;
        curr1->next = list1;
        for ( int i = 0; i < a; ++i ) {
            curr1 = curr1->next;
        }
        ListNode* curr2 = curr1;
        for ( int i = 0; i <= b - a + 1; ++i ) {
            curr2 = curr2->next;
            // FIXME : delete curr2
        }
        ListNode* list2_tail = list2;
        while ( list2_tail->next != nullptr ) {
            list2_tail = list2_tail->next;
        }
        curr1->next = list2;
        list2_tail->next = curr2;
        curr1 = dummy->next;
        delete dummy;
        return curr1;
    }
};
