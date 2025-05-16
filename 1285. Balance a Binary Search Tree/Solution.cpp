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
    TreeNode* helper(vector<int>& v, int left, int right){
        if(left > right) return NULL;
        
        int mid = left + (right-left)/2;
        
        TreeNode* root = new TreeNode(v[mid]);
        root->left = helper(v, left, mid-1);
        root->right = helper(v, mid+1, right);
        return root;
    }
    void dfs(TreeNode* root, vector<int>& v){
        if(!root) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return helper(v, 0, v.size()-1);
    }
};