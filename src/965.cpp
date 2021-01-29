#include "structure.h"
#include <stack>

using std::stack;

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if ( root == nullptr ) {
            return true;
        }
        bool left_flag = root->left == nullptr
                || (root->left->val == root->val && isUnivalTree(root->left));
        bool right_flag = root->right == nullptr
                || (root->right->val == root->val && isUnivalTree(root->right));
        return left_flag && right_flag;
    }
};


class Solution2 {
public:
    bool isUnivalTree(TreeNode* root) {
        if ( root == nullptr ) {
            return true;
        }
        int val = root->val;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* last = nullptr;

        while ( !stk.empty() || cur != nullptr ) {
            while ( cur != nullptr ) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            if ( cur->right == nullptr || last == cur->right ) {
                if ( cur->val != val ) {
                    return false;
                }
                stk.pop();
                last = cur;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        return true;
    }
};
