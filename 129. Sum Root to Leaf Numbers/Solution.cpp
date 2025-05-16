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
    long long ans = 0;
    void dfs(TreeNode* root, int temp){
        if(!root) return;
        if(!root->left && !root->right){
            temp = temp * 10 + (root->val);
            ans += temp;
            return;
        }
        temp = temp * 10 + (root->val);
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    int sumNumbers(TreeNode* root) {
        int temp = 0;
        dfs(root, temp);
        return (int)ans;
    }
};