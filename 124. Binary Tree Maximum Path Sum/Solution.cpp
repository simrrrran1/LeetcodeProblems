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
    int dfs(TreeNode* root, int& sum){
        if(!root) return 0;
        int leftMax = dfs(root->left, sum);
        int rightMax = dfs(root->right, sum);

        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        sum = max(sum, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
};