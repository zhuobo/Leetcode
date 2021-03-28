// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.28
// Filename:        173.cpp
// Descripton:       

#include "structure.h"

#include <stack>
#include <vector>

using std::stack;
using std::vector;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* ret = stk_.top();
        stk_.pop();
        pushLeft(ret->right);
        return ret->val;
    }
    
    bool hasNext() {
        return !stk_.empty();
    }
private:
    void pushLeft(TreeNode* root) {
        while ( root != nullptr ) {
            stk_.push(root);
            root = root->left;
        }
    }
    stack<TreeNode*> stk_;
};

class BSTIterator2 {
public:
    BSTIterator2(TreeNode* root) : index_(0) {
        inOrder(root);
    }

    int next() {
        return nums_[index_++];
    }

    bool hasNext() {
        return index_ < nums_.size();
    }
private:
    void inOrder(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode*        curr = root;
        while ( !stk.empty() || curr != nullptr ) {
            while ( curr != nullptr ) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            nums_.push_back(curr->val);
            curr = curr->right;
        }
    }
    vector<int> nums_;
    int         index_;
};
