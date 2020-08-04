#include <iostream>
#include <vector>
#include "0102.h"
#include "structure.h"
int main() {
    Solution s;
    TreeNode *root = new TreeNode(3); 
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    std::vector<std::vector<int>> res = s.levelOrder(root);
    for ( auto v : res ) {
        for ( auto num : v ) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
