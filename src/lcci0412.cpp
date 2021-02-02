#include "structure.h"

class Solution {
private:
    int pathCount(TreeNode* root, int target) {
        if ( root == nullptr ) {
            return 0;
        }
        int count = 0;
        if ( target == root->val ) {
            ++count;
        }
        int l = pathCount(root->left, target - root->val );
        int r = pathCount(root->right, target - root->val );
        return count + l + r;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if ( root == nullptr ) {
            return 0;
        }
        return pathCount(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};


class Solution2 {
private:
    int res;

    void backtrack(vector<int>& presum, TreeNode* root, int target, int len) {
        if ( root == nullptr ) {
            return;
        }
        presum.push_back(presum.back() + root->val);
        for ( int i = 0; i < len; ++i ) {
            if ( presum.back() - presum[i] == target ) ++res;
        }
        backtrack(presum, root->left, target, len + 1);
        if ( root->left != nullptr ) {
            presum.pop_back();
        }
        backtrack(presum, root->right, target, len + 1);
        if ( root->right != nullptr ) {
            presum.pop_back();
        } 
    }
public:
    int pathSum(TreeNode* root, int sum) {
        res = 0;
        vector<int> presum;
        presum.push_back(0);
        backtrack(presum, root, sum, 1);
        return res;
    }
};
