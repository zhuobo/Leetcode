#include <iostream>
#include "0513.h"
#include "structure.h"
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int res = s.findBottomLeftValue(root);
    std::cout << res << std::endl;

}
