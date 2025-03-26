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
    int height(TreeNode* root, bool& ans){
        if(!root) return 0;
        int lH = height(root->left, ans);
        int rH = height(root->right, ans);
        if(abs(rH - lH) > 1) ans = false;
        return 1 + max(lH, rH);
    }
    bool isBalanced(TreeNode* root) {
        if(!root || (!root->left && !root->right))return true;
        bool ans = true;
        height(root, ans);
        return ans;
    }
};