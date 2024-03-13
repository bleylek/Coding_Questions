/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
*/

#include <iostream>
#include <vector>
using namespace std;

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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->val == val) {
                return curr;
            } else if (curr->val > val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return curr; // If the node is not found, curr will be nullptr
    }
};


// Helper function to insert nodes into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    // Nodes to create the example BST: root = [4,2,7,1,3]
    int nodes[] = {4, 2, 7, 1, 3};
    TreeNode* root = nullptr;
    for (int val : nodes) {
        root = insertIntoBST(root, val);
    }

    Solution solution;
    // Example: search for the value 2 in the BST
    int valToSearch = 2;
    TreeNode* result = solution.searchBST(root, valToSearch);

    // Assuming result is the node where val = 2, which is found in the BST
    if (result) {
        cout << "Found node with value " << valToSearch << endl;
        if (result->left) cout << "Left child: " << result->left->val << endl;
        if (result->right) cout << "Right child: " << result->right->val << endl;
    } else {
        cout << "Value " << valToSearch << " not found in the BST." << endl;
    }

    return 0;
}