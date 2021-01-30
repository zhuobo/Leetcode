#include "structure.h"

class Solution {
private:
    int sum;
public:
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;     
        helper(root, 0);
        return sum;
    }

    // cur: sum before current node
    void helper(TreeNode* root, int cur) {
        if ( root == nullptr ) return;
        if ( root->left == nullptr && root->right == nullptr ) {
            sum += cur * 2 + root->val;
            return;
        }
        helper(root->left, cur * 2 + root->val);
        helper(root->right, cur * 2 + root->val);
    }
};
