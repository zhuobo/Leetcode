#include <vector>
#include <unordered_set>
#include "structure.h"

using namespace std;

class Solution {
private:
    vector<TreeNode*> trees;

    TreeNode* dfs(TreeNode* root, unordered_set<int>& ival) {
        if ( root == nullptr ) {
            return root;
        }
        root->left = dfs(root->left, ival);
        root->right = dfs(root->right, ival);
        if ( ival.find(root->val) != ival.end() ) {
            if (root->left != nullptr ) {
                trees.push_back(root->left);
            }
            if ( root->right != nullptr ) {
                trees.push_back(root->right);
            }
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> ival(to_delete.begin(), to_delete.end());
        root = dfs(root, ival);
        if ( root != nullptr ) trees.push_back(root);
        return trees;
    }
};
