#include "structure.h"

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while ( head != nullptr ) {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};
