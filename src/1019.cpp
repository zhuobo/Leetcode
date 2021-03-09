#include <iostream>
#include <vector>
#include <stack>
#include <UTILITY>

using std::vector;
using std::stack;
using std::pair;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res(size(head), 0);
        stack<pair<int, int>> stk; // num->index
        ListNode *curr = head;
        int index = 0;
        while ( curr != nullptr ) {
            while ( !stk.empty() && stk.top().first < curr->val ) {
                res[stk.top().second] = curr->val;
                stk.pop();
            }
            stk.emplace(curr->val, index++);
            curr = curr->next;
        }
        return res;
    }

    int size(ListNode *head) {
        int count = 0;
        while ( head != nullptr ) {
            ++count;
            head = head->next;
        }
        return count;
    }
};
