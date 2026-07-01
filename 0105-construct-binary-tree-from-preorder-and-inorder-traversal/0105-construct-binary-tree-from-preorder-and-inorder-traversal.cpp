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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrderIndexMap;

        for (int i = 0; i < (int)inorder.size(); i++) {
            inOrderIndexMap[inorder[i]] = i;
        }

        return splitTree(preorder, inOrderIndexMap, 0, 0, (int)inorder.size() - 1);
    }

private:
    TreeNode* splitTree(vector<int>& preorder,
                        unordered_map<int, int>& inOrderIndexMap,
                        int rootIndex, int left, int right) {

        TreeNode* root = new TreeNode(preorder[rootIndex]);

        int mid = inOrderIndexMap[preorder[rootIndex]];

        if (mid > left)
            root->left  = splitTree(preorder, inOrderIndexMap,
                                    rootIndex + 1, left, mid - 1);

        if (mid < right)
            root->right = splitTree(preorder, inOrderIndexMap,
                                    rootIndex + mid - left + 1, mid + 1, right);

        return root;
    }
};