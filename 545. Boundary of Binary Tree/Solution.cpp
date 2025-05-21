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
    bool isLeaf(TreeNode* root){
        return (root && !root->left && !root->right);
    }
    void leftBoundary(TreeNode* root, vector<int>& ans){
        TreeNode* node = root->left;
        while(node){
            if(!isLeaf(node)) ans.push_back(node->val);
            if(node->left) node = node->left;
            else node = node->right;
        }
    }

    void rightBoundary(TreeNode* root, vector<int>& ans){
        TreeNode* node = root->right;
        vector<int> temp;
        while(node){
            if(!isLeaf(node)) temp.push_back(node->val);
            if(node->right) node = node->right;
            else node = node->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }

    void leafNode(TreeNode* root, vector<int>& ans){
        if(!root) return;
        if(isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }
        leafNode(root->left, ans);
        leafNode(root->right, ans);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        if(!isLeaf(root)) ans.push_back(root->val);
        leftBoundary(root, ans);
        leafNode(root, ans);
        rightBoundary(root, ans);
        return ans;
    }
};