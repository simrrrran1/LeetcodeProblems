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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* rightSide = NULL;
            int k = q.size();

            while(k){
                TreeNode* front = q.front();
                q.pop();
                if(front){
                    rightSide = front;
                    q.push(front->left);
                    q.push(front->right);
                }
                k--;
            }
            if(rightSide){
                ans.push_back(rightSide->val);
            }
        }

        return ans;

    }
};