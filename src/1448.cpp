#include "structure.h"
#include <climits>
#include <algorithm>

using std::max;
using std::min;

class Solution {
private:
    int helper(TreeNode* root, int max_num) {
        if ( root == nullptr ) {
            return 0;
        }
        int count = 0;
        if ( root->val >= max_num ) {
            ++count;
        }
        int left = helper(root->left, max(max_num, root->val));
        int right = helper(root->right, max(max_num, root->val));
        return count + left + right;
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};
