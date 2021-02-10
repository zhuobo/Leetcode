#include "structure.h"
#include <algorithm>

using std::min;
using std::max;

class Solution {
private:
    int max_dist;

    void dfs(TreeNode* root, int max_num, int min_num) {
        if ( root == nullptr ) return;
        max_dist = max(max_dist, abs(root->val - max_num));
        max_dist = max(max_dist, abs(root->val - min_num));
        max_num = max(max_num, root->val);
        min_num = min(min_num, root->val);
        dfs(root->left, max_num, min_num);
        dfs(root->right, max_num, min_num);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        max_dist = 0;
        if ( root == nullptr ) return max_dist;
        dfs(root, root->val, root->val);
        return max_dist;
    }
};
