#include "structure.h"

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if ( root == nullptr ) {
            return new TreeNode(val);
        }
        if ( root->val < val ) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            root = new_root;
        } else {
            TreeNode* curr = root;
            while ( curr->right != nullptr && curr->right->val > val ) {
                curr = curr->right;
            }
            if ( curr->right == nullptr ) {
                curr->right = new TreeNode(val);
            } else {
                TreeNode* node = new TreeNode(val);
                node->left = curr->right;
                curr->right = node;
            }
        }
        return root;
    }
};
