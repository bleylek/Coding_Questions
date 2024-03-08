/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]


Example 2:

Input: root = []
Output: []


Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        inorder(root, v);
        return v;
    }
private:
    void inorder(TreeNode* root, std::vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

// Helper function to print the vector
void printVector(const std::vector<int>& v) {
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Main function to test the inorderTraversal method
int main() {
    // Example 1:
    TreeNode *root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);

    Solution sol;
    std::vector<int> result1 = sol.inorderTraversal(root1);
    std::cout << "Example 1: ";
    printVector(result1);

    // Example 2:
    // Just use nullptr as the root since the tree is empty
    std::vector<int> result2 = sol.inorderTraversal(nullptr);
    std::cout << "Example 2: ";
    printVector(result2);

    // Example 3:
    TreeNode *root3 = new TreeNode(1);
    std::vector<int> result3 = sol.inorderTraversal(root3);
    std::cout << "Example 3: ";
    printVector(result3);

    // Clean up dynamically allocated memory
    delete root1->right->left;
    delete root1->right;
    delete root1;
    delete root3;

    return 0;
}
