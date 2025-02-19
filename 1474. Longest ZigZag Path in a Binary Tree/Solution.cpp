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
    int ans=0;
    void dfs(TreeNode* root, bool left, int curr){
        if(!root)return;
        ans = max(ans, curr);
        if(left){
            dfs(root->right, false, curr+1);
            dfs(root->left, true, 1);
        }else{
            dfs(root->right, false, 1);
            dfs(root->left, true, curr+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 0;
        dfs(root, true, 0);
        return ans;
    }
};