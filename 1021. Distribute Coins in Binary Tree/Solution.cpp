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
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left_extra = dfs(root->left);
        int right_extra = dfs(root->right);
        int extra_coins = root->val - 1 + left_extra + right_extra;
        ans += abs(extra_coins);
        return extra_coins;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};