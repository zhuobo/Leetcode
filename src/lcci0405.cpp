#include "structure.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* last = nullptr;
        while ( !stk.empty() || curr != nullptr ) {
            while ( curr != nullptr ) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if ( last != nullptr && curr->val <= last->val ) {
                return false;
            }
            last = curr;
            curr = curr->right;
        }
        return true;
    }
};
