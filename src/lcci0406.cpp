#include "structure.h"


// solution1: in order traversal to find the node next to p


// solution2: 
// 1. find node p
// 2. find left most node in the right tree of p
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if ( root == nullptr || p == nullptr ) {
            return nullptr;
        }
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while ( curr->val != p->val ) {
            if ( p->val > curr->val ) {
                curr = curr->right;
            } else {
                prev = curr;
                curr = curr->left;
            }
        }
        // curr is pointing to p
        if ( curr->right != nullptr ) {
            curr = curr->right;
            while ( curr->left != nullptr ) {
                curr = curr->left;
            }
        } else {
            return prev;
        }
        return curr == p ? prev : curr;
    }
};
