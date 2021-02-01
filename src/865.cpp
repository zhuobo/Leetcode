#include "structure.h"
#include <algorithm>
#include <utility>

using std::pair;


class Solution {
private:
    int depth(TreeNode* root) {
        if ( root == nullptr ) {
            return 0;
        }
        return 1 + std::max(depth(root->left), depth(root->right));
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int left_depth = depth(root->left), right_depth = depth(root->right);
        if ( left_depth == right_depth ) {
            return root;
        }
        if ( left_depth < right_depth ) {
            return subtreeWithAllDeepest(root->right);
        }
        return subtreeWithAllDeepest(root->left);
    }
};


class Solution2 {
private:
    pair<TreeNode*, int> depth(TreeNode* root) {
        if ( root == nullptr ) {
            return {root, 0};
        }
        auto L = depth(root->left), R = depth(root->right);
        if ( L.second > R.second ) {
            return {L.first, L.second + 1};
        }
        if ( L.second < R.second ) {
            return {R.first, R.second + 1};
        }
        return { root, L.second + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).first;
    }
};

