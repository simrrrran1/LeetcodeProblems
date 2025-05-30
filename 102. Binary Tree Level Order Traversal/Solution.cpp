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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int k = q.size();
            vector<int> v;

            while(k--){
                TreeNode* front = q.front();
                q.pop();
                
                v.push_back(front->val);
                if(front->left) 
                    q.push(front->left);
                if(front->right) 
                    q.push(front->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};