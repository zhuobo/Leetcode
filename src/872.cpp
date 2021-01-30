#include <vector>
#include <stack>
#include "structure.h"

using std::vector;
using std::stack;


class Solution {
private:
    vector<int> leaves(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* last = nullptr;
        vector<int> leaves;
        while ( !stk.empty() || cur != nullptr ) {
            while ( cur != nullptr ) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            if ( cur->right == nullptr || last == cur->right ) {
                // visit cur
                if ( cur->left == nullptr && cur->right == nullptr ) {
                    leaves.push_back(cur->val);
                }
                stk.pop();
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1 = leaves(root1);
        vector<int> leaves2 = leaves(root2);
        return leaves1 == leaves2;
    }
};
