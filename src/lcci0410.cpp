#include "structure.h"
#include <string>
#include <algorithm>
using std::string;

class Solution {
private:
    string in_order(TreeNode* root) {
        if ( root == nullptr ) {
            return "#";
        }
        string l = in_order(root->left);
        string r = in_order(root->right);
        return l + std::to_string(root->val) + r;
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string str1 = in_order(t1), str2 = in_order(t2);
        return str1.find(str2) != string::npos;
    }
};

class Solution2 {
private:
    bool equal(TreeNode* t1, TreeNode* t2) {
        if ( t1 == nullptr && t2 == nullptr ) {
            return true;
        }
        if ( t1 == nullptr || t2 == nullptr ) {
            return false;
        }
        return t1->val == t2->val && equal(t1->left, t2->left) && equal(t1->right, t2->right);

    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if ( t1 == nullptr ) {
            return t2 == nullptr;
        }
        return equal(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};
