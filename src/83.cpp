// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.26
// Filename:        83.cpp
// Descripton:      

#include "structure.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == nullptr ) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        curr->next = head;
        head = head->next;
        curr = curr->next;
        while ( head != nullptr ) {
            if ( head->val != curr->val ) {
                curr->next = head;
                curr = curr->next;
            } // FIXME else delete the node
            head = head->next;
        }
        curr->next = nullptr;
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == nullptr ) {
            return head;
        }
        ListNode* curr = head;
        while ( curr->next ) {
            if ( curr->val == curr->next->val ) {
                curr->next = curr->next->next;
                // FIXME delete node next
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
