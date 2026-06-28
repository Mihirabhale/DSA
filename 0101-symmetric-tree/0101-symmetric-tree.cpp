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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* left  = q1.front(); q1.pop();
            TreeNode* right = q2.front(); q2.pop();

            if (left == nullptr && right == nullptr) continue;  // both null ✅
            if (left == nullptr || right == nullptr) return false; // one null ❌
            if (left->val != right->val) return false;  // different values ❌

            // push in MIRROR order
            q1.push(left->left);
            q2.push(right->right);

            q1.push(left->right);
            q2.push(right->left);
        }

        return true;
    }
};