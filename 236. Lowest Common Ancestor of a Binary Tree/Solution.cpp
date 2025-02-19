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
        if(!root || (root == p || root == q) )return root;
        
        TreeNode* leftRoot =  lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRoot =  lowestCommonAncestor(root->right, p, q);

        if(leftRoot && rightRoot) return root; //both p,q are in diff trees
        if(leftRoot)return leftRoot; // p, q belong to same tree
        else return rightRoot;
        return NULL; // p, q are not there in both left and right trees

    }
};