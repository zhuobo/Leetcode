#include "structure.h"

#include <vector>

using std::vector;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
        ListNode* curr = root;
        while ( curr != nullptr ) {
            ++count;
            curr = curr->next;
        }
        int len = count / k;
        int remain = count % k;
        vector<ListNode*> res;
        curr = root;
        // remain个长度为len + 1, 剩余长度为len
        for ( int i = 0; i < remain; ++i ) {
            res.push_back(curr);
            for ( int j = 0; j < len; ++j ) {
                curr = curr->next;
            }
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        for ( int i = 0; i < k - remain; ++i ) {
            res.push_back(curr);
            for ( int j = 0; j < len - 1; ++j ) {
                curr = curr->next;
            }
            if ( curr != nullptr ) {
                ListNode* next = curr->next;
                curr->next = nullptr;
                curr = next;
            }
        }
        return res;
    }
};
