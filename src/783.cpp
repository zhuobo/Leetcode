#include <stack>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    int min_dist = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        int last_num = INT_MIN;
        while ( !stk.empty() || cur != nullptr ) {
            while ( cur != nullptr ) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if ( last_num != INT_MIN ) {
                min_dist = min(min_dist, cur->val - last_num);
                if ( min_dist == 1 ) break;
            }
            last_num = cur->val;
            cur = cur->right;
        }
        return min_dist;
    }
};
