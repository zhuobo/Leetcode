#include <stack>
#include "structure.h"

using std::stack;

class Solution {
private:
    int total;
public:
    Solution() : total(0){ }

    TreeNode* bstToGst(TreeNode* root) {
        if ( root == nullptr ) return root;
        root->right = bstToGst(root->right);
        total += root->val;
        root->val = total;
        root->left = bstToGst(root->left);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        int curr_sum = 0;
        while( !stk.empty() || curr != nullptr ) {
            // 右子树先入栈
            while ( curr != nullptr ) {
                stk.push(curr);
                curr = curr->right;
            }
            curr = stk.top();
            stk.pop();
            curr_sum += curr->val;
            curr->val = curr_sum;
            curr = curr->left;
        }
        return root;
    }
};
