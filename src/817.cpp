#include "structure.h"

#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

// not repeated
class Solution1 {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> nums(G.begin(), G.end());
        int count = 0;
        while ( head != nullptr ) {
            if ( nums.find(head->val) != nums.end() ) {
                ++count;
                while ( head != nullptr && nums.find(head->val) != nums.end() ) {
                    head = head->next;
                }
            } else {
                head = head->next;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> nums(G.begin(), G.end());
        int count = 0;
        while ( head != nullptr ) {
            if ( nums.find(head->val) != nums.end() && 
                (head->next == nullptr || nums.find(head->next->val) == nums.end()) ) {
                    ++count;
            }
            head = head->next;
        }
        return count;
    }
};
