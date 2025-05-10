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
    int count = 0;
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, 0};

        pair<int,int> leftPair = dfs(root->left);
        pair<int,int> rightPair = dfs(root->right);

        int sum = root->val + leftPair.first + rightPair.first;
        int cnt = 1 + leftPair.second + rightPair.second;

        int avg = sum / cnt;

        if(avg == root->val) count++;

        return {sum, cnt};

    }

    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return count;
    }
};