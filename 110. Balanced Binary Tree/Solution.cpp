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
    int helper(TreeNode* root, bool& ans){
        if(!root)return 1;
        int lH=helper(root->left,ans);
        int rH=helper(root->right,ans);
        if(abs(rH-lH)>1)ans=false;
        return 1+max(lH,rH);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(!root->left&&!root->right)return true;
        bool ans=true;
        helper(root,ans);
        return ans;

    }
};