#include <queue>
#include "structure.h"

using std::queue;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> nodes;
public:
    // _root is not nullptr
    CBTInserter(TreeNode* _root) : root(_root) {
        queue<TreeNode*> que;
        que.push(root);
        while ( !que.empty() ) {
            TreeNode* curr = que.front();
            que.pop();
            if ( curr->left == nullptr || curr->right == nullptr ) {
                nodes.push(curr);
            }
            if ( curr->left != nullptr ) {
                que.push(curr->left);
            }
            if ( curr->right != nullptr ) {
                que.push(curr->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode* new_node = new TreeNode(v);
        TreeNode* curr = nodes.front();
        if ( curr->left == nullptr ) {
            curr->left = new_node;
        } else {
            curr->right = new_node;
            nodes.pop();
        }
        nodes.push(new_node);
        return curr->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
