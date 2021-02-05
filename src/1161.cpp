#include <queue>
#include <climits>
#include "structure.h"

using std::queue;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if ( root == nullptr ) return 0;
        queue<TreeNode*> que;
        int level = 0, res= level;
        int max_sum = INT_MIN;
        que.push(root);
        while ( !que.empty() ) {
            int size = que.size();
            int cur_sum = 0;
            while ( size-- ) {
                TreeNode* node = que.front();
                que.pop();
                cur_sum += node->val;
                if ( node->left != nullptr ) {
                    que.push(node->left);
                }
                if ( node->right != nullptr ) {
                    que.push(node->right);
                }
            }
            ++level;
            if ( cur_sum > max_sum ) {
                res = level;
                max_sum = cur_sum;
            }
        }
        return res;
    }
};
