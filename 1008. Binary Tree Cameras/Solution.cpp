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
    // 0 : not covered
    // 1 : has camera
    // 2 : covered by camera
    int camera = 0;
    int dfs(TreeNode* root){
        if(!root) return 1;
        int leftNode = dfs(root->left);
        int rightNode = dfs(root->right);

        if(leftNode == 0 || rightNode == 0){
            camera++;
            return 2;
        }else if(leftNode == 2 || rightNode == 2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        return dfs(root) == 0 ? camera+1 : camera;
    }
};