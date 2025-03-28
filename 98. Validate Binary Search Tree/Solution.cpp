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
    bool isBST(TreeNode* root, long long left, long long right){
        if(!root) return true;
        if( !(left < root->val && root->val < right) ) return false;
        return isBST(root->left, left, root->val) && isBST(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    
    }
};