#include <iostream>
#include <vector>
#include <stack>
#include "structure.h"

using namespace std;

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* last = nullptr;
        while ( !stk.empty() || cur != nullptr ) {
            while ( cur != nullptr ) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if ( last == nullptr ) {
                root = cur;
            } else {
                last->right = cur;
            }
            cur->left = nullptr;
            last = cur;
            cur = cur->right;
        }
        return root;
    }
};
