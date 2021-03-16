#include "structure.h"
#include <algorithm>

using std::abs;

class Solution {
private:
    int steps;
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
    }

    int dfs(TreeNode* root) {
        if ( root == nullptr ) return 0;
        int left_count = dfs(root->left);
        int right_count = dfs(root->right);
        steps += abs(left_count) + abs(right_count);
        return root->val + left_count + right_count - 1;
    }
};
