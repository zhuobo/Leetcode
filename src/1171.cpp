#include "structure.h"
#include <unordered_map>

using std::unordered_map;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m; // pre_sum->list
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int pre_sum;
        for ( ListNode *curr = dummy; curr != nullptr; curr = curr->next) {
            pre_sum += curr->val;
            m[pre_sum] = curr;
        }
        pre_sum = 0;
        for ( ListNode *curr = dummy; curr != nullptr; curr = curr->next )  {
            pre_sum += curr->val;
            curr->next = m[pre_sum]->next;
        }
        return dummy->next;
    }
};
