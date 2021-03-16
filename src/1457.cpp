#include <vector>
#include "structure.h"

using std::vector;

class Solution {
private:
    vector<int> count;
    int res;

    void dfs(TreeNode* root) {
        if ( root == nullptr ) return;
        ++count[root->val];
        if ( root->left == nullptr && root->right == nullptr ) {
            if ( palindromic(count) ) ++res;
            return;
        }
        dfs(root->left);
        if ( root->left != nullptr ) --count[root->left->val];
        dfs(root->right);
        if ( root->right != nullptr ) --count[root->right->val];
    }

    bool palindromic(vector<int>& count) {
        int odd_count = 0;
        for ( int i = 1; i <= 9; ++i ) {
            if ( (count[i] & 1) == 1 ) ++odd_count;
        }
        return odd_count <= 1;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        count.resize(10, 0);
        res = 0;
        dfs(root);
        return res;
    }
};
