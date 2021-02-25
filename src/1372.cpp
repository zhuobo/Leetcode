#include <algorithm>
#include "structure.h"

using std::max;

class Solution {
private:
    int max_len;

    // left_dir: prev direction, true is for left
    void dfs(TreeNode* root, bool left_dir, int len) {
        if ( root == nullptr ) {
            return;
        }
        max_len = max(max_len, len);
        if ( left_dir ) {
            dfs(root->left, true, 1);
            dfs(root->right, false, 1 + len);
        } else {
            dfs(root->left, true, 1 + len);
            dfs(root->right, false, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        max_len = 0;
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);
        return max_len;
    }
};
