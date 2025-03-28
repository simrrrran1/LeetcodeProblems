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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        while(!q.empty()){
            int k = q.size();
            vector<int> v;
            for(int i=0; i<k; i++){
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(level % 2) reverse(v.begin(), v.end());
            ans.push_back(v);
            level += 1;
        }
        return ans;
    }
};