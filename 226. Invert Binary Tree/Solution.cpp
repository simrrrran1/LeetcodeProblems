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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        if(!root->left && !root->right)return root;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        TreeNode* right1=invertTree(root->left);
        TreeNode* left1=invertTree(root->right);
        root->left=right1;
        root->right=left1;
        return root;
    }
};