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



class Solution2 {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        stack<TreeNode*> stk;
        vector<bool> del(1001, false);
        vector<TreeNode*> res;
        for ( int num : to_delete ) del[num] = true;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        if ( root != nullptr && !del[root->val] ) {
            res.push_back(root);
        }
        while ( !stk.empty() || curr != nullptr ) {
            while ( curr != nullptr ) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            if ( curr->right == nullptr || curr->right == prev ) {
                stk.pop();
                if ( curr->left != nullptr && del[curr->left->val] ) {
                    curr->left = nullptr;
                }
                if ( curr->right != nullptr && del[curr->right->val] ) {
                    curr->right = nullptr;
                }
                if ( del[curr->val] ) {
                    if ( curr->left != nullptr ) res.push_back(curr->left);
                    if ( curr->right != nullptr ) res.push_back(curr->right);
                }
                prev = curr;
                curr = nullptr;
            } else {
                curr = curr->right;
            }
        }
        return res;
    }
};
