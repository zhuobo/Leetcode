#include <queue>
#include <climits>
#include "structure.h"

using std::queue;


class Solution {
private:
    int depth(TreeNode* root) {
        if ( root == nullptr ) {
            return 0;
        }
        return 1 + std::max(depth(root->left), depth(root->right));
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int max_depth = depth(root);
        queue<TreeNode*> que;
        que.push(root);
        int cur_level = 1, res = 0;
        while ( !que.empty() ) {
            int size = que.size();
            while ( size-- ) {
                TreeNode* node = que.front();
                que.pop();
                if ( cur_level == max_depth ) {
                    res += node->val;
                }
                if ( node->left ) que.push(node->left);
                if ( node->right ) que.push(node->right);
            }
            ++cur_level;
        }
        return res;
    }
};
