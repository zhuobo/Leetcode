#include "structure.h"
#include <climits>
#include <algorithm>
using namespace std;


class Solution {
private:
    int max_len;
    
    int helper(TreeNode* root) {
        if ( root == nullptr ) {
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        int left_contrib = 0, right_contrib = 0;
        if ( root->left != nullptr && root->left->val == root->val) {
            left_contrib += 1 + left;
        }
        if ( root->right != nullptr && root->right->val == root->val ) {
            right_contrib += 1 + right;
        }
        max_len = max(max_len, left_contrib + right_contrib);
        return max(left_contrib, right_contrib);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        max_len = 0;
        helper(root);
        return max_len;
    }
};
