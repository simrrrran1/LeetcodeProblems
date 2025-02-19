/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;

        if(root == p || root == q)return root;
        
        TreeNode* leftRoot =  lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRoot =  lowestCommonAncestor(root->right, p, q);

        if(leftRoot && rightRoot) return root;
        if(leftRoot)return leftRoot;
        else return rightRoot;
        return NULL;

    }
};