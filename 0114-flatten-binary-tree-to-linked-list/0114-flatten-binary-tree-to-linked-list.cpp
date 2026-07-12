/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // flatten left and right subtrees first
        flatten(root->left);
        flatten(root->right);

        // store right subtree
        TreeNode* rightSubtree = root->right;

        // move left subtree to right
        root->right = root->left;
        root->left  = nullptr;

        // find end of new right subtree
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }

        // attach original right subtree
        curr->right = rightSubtree;
    }
};