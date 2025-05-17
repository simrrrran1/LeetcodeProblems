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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start1, int start2, int end1, int end2){
        if(start1 > end1 || start2 > end2) return NULL;
        TreeNode* root = new TreeNode(preorder[start1]);
        int i=0; 
        while(preorder[start1] != inorder[i]) i++;
        root->left = helper(preorder, inorder, start1+1, start2, start1-start2+i, i-1);
        root->right = helper(preorder, inorder, start1+i-start2+1, i+1, end1, end2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return helper(preorder, inorder, 0, 0, n-1, n-1);
    }
};


//preorder = [3, 9, 20, 15, 7]
//inorder =  [9, 3, 15, 20, 7]
