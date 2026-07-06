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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int current) {
        if (root == nullptr) return 0;

        current = current * 10 + root->val;

        // leaf node — return the number formed
        if (root->left == nullptr && root->right == nullptr) {
            return current;
        }

        int l =dfs(root->left, current);
        int r =dfs(root->right, current);

        return l + r;
    }
};