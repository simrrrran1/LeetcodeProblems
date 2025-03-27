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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        int maxLevel = 1;
        int maxSum = root->val;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int k = q.size();
            level++;
            int sum = 0;
            for(int i=0; i<k; i++){
                TreeNode* front = q.front();
                q.pop();
                sum += (front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(maxSum < sum){
                maxSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;

    }
};