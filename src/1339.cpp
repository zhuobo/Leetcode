#include "structure.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int total;
    int best;
public:
    int maxProduct(TreeNode* root) {
        total = 0;
        best = 0;
        get_sum(root);
        get_best(root);
        int MOD = 1000000007;
        return long(((best % MOD)) * long(((total - best) % MOD))) % MOD;
    }
    int get_best(TreeNode* root) {
        if ( root == nullptr ) return 0;
        int curr = get_best(root->left) + get_best(root->right) + root->val;
        if ( abs(best * 2 - total) > abs(curr * 2 - total) ) {
            best = curr;
        }
        return curr;
    }

    void get_sum(TreeNode* root) {
        if ( root == nullptr ) return;
        total += root->val;
        get_sum(root->left);
        get_sum(root->right);
    }
};
