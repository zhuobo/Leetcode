#include <queue>
#include "structure.h"

using std::queue;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> que;
        que.push(root);
        while ( !que.empty() ) {
            int size = que.size();
            // x and y existed in same level
            bool x_existed = false, y_existed = false;
            while ( size-- ) {
                TreeNode* cur = que.front();
                que.pop();
                bool x_child = false,y_child = false;
                if ( cur->val == x ) {
                    x_existed = true;
                }
                if ( cur->val == y ) {
                    y_existed = true;
                }
                // children with the same parent
                if ( cur->left != nullptr && cur->right != nullptr ) {
                    if ( cur->left->val == x || cur->right->val == x ) {
                        x_child = true;
                    }
                    if ( cur->left->val == y || cur->right->val == y ) {
                        y_child = true;
                    }
                }
                if ( x_child && y_child ) {
                    return false;
                }
                if ( cur->left != nullptr ) {
                    que.push(cur->left);
                }
                if ( cur->right != nullptr ) {
                    que.push(cur->right);
                }
            }
            if ( x_existed && y_existed ) {
                return true;
            }
        }
        return false;
    }
};
