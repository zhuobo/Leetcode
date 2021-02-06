#include <queue>
#include "structure.h"

using std::queue;

// solution1: DFS
class Solution {
    int res;
    void dfs(TreeNode* cur, TreeNode* parent, TreeNode* gparent) {
        if ( cur == nullptr ) {
            return;
        } 
        if ( gparent != nullptr && gparent->val % 2 == 0 ) {
             res += cur->val;
        }
        dfs(cur->left, cur, parent);
        dfs(cur->right, cur, parent);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        dfs(root, nullptr, nullptr);
        return res;
    }
};

// Solution2: BFS
class Solution2 {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while( !que.empty() ) {
            TreeNode* node = que.front();
            que.pop();
            if ( node->val % 2 == 0 ) {
                if ( node->left != nullptr ) {
                    if ( node->left->left != nullptr ) {
                        res += node->left->left->val;
                    }
                    if ( node->left->right != nullptr ) {
                        res += node->left->right->val;
                    }
                }
                if ( node->right != nullptr ) {
                    if ( node->right->left != nullptr ) {
                        res += node->right->left->val;
                    }
                    if ( node->right->right != nullptr ) {
                        res += node->right->right->val;
                    }
                }
            }
            if ( node->left != nullptr ) que.push(node->left);
            if ( node->right != nullptr ) que.push(node->right);
        }
        return res;
    }
};

