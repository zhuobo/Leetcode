#include <unordered_set>
#include "structure.h"

using std::unordered_set;

class FindElements {
private:
    TreeNode* root;
    unordered_set<int> nums;

    void dfs(TreeNode* root, int val) {
        if ( root == nullptr ) return;
        root->val = val;
        nums.insert(val);
        dfs(root->left, 2 * val + 1);
        dfs(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
        this.root = root;
    }
    
    bool find(int target) {
        return nums.find(target) != nums.end();
    }
};
