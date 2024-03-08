/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;
        if(root->val > high)
            return rangeSumBST(root->left, low, high);
        if(root->val < low)
            return rangeSumBST(root->right, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// Helper function to create a new TreeNode.
TreeNode* newNode(int data) {
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = temp->right = nullptr;
    return temp;
}

int main() {
    // Example 1
    TreeNode* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(15);
    root1->left->left = newNode(3);
    root1->left->right = newNode(7);
    root1->right->right = newNode(18);

    Solution sol;
    int sum1 = sol.rangeSumBST(root1, 7, 15);
    std::cout << "Sum1: " << sum1 << std::endl; // Output: 32

    // Example 2
    TreeNode* root2 = newNode(10);
    root2->left = newNode(5);
    root2->right = newNode(15);
    root2->left->left = newNode(3);
    root2->left->right = newNode(7);
    root2->left->left->left = newNode(1);
    root2->left->right->left = newNode(6);
    root2->right->left = newNode(13);
    root2->right->right = newNode(18);

    int sum2 = sol.rangeSumBST(root2, 6, 10);
    std::cout << "Sum2: " << sum2 << std::endl; // Output: 23

    return 0;
}
