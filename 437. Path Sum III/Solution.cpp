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
    int count=0;
    void helper(TreeNode*root,long long int targetSum){
        if(!root)return;
        if(root->val==targetSum)count++;
        helper(root->left,targetSum-root->val);
        helper(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root){
            helper(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return count;
        
    }
};