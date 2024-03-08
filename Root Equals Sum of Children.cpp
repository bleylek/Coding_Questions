/*
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.

Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

 

Example 1:


Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.


Example 2:


Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.
 

Constraints:

The tree consists only of the root, its left child, and its right child.
-100 <= Node.val <= 100
*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkTree(TreeNode* root) {
        return (root->val == root->left->val + root->right->val);
    }
};

int main() {
    // Example 1:
    TreeNode *root1 = new TreeNode(10);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(6);
    
    Solution sol;
    bool result1 = sol.checkTree(root1);
    std::cout << "Example 1: " << (result1 ? "true" : "false") << std::endl;

    // Example 2:
    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(1);

    bool result2 = sol.checkTree(root2);
    std::cout << "Example 2: " << (result2 ? "true" : "false") << std::endl;

    // Clean up dynamically allocated memory
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
