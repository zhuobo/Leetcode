// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.25
// Filename:        
// Descripton:       

#include "structure.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        bool      repeated = false;
        while ( head != nullptr ) {
            while ( head->next != nullptr && head->val == head->next->val ) {
                repeated = true;
                head = head->next;
            }
            if ( repeated ) {
                head = head->next;
            }
            if ( head != nullptr ) {
                if ( (head->next != nullptr && head->val != head->next->val)
                    || head->next == nullptr ) {
                    curr->next = head;
                    curr = curr->next;
                    head = head->next;
                }
            }
            repeated = false;
        }
        curr->next = nullptr;
        return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        dummy->next = head;
        while ( curr->next && curr->next->next ) {
            if ( curr->next->val == curr->next->next->val ) {
                ListNode* temp = curr->next;
                while ( temp->next && temp->val == temp->next->val ) {
                    temp = temp->next;
                }
                curr->next = temp->next;
            } else {
                curr = curr->next;
            }
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};

