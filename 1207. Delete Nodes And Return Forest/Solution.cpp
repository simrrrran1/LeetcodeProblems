class Solution {
public:
    TreeNode* dfs(TreeNode* root, unordered_set<TreeNode*>& res, unordered_map<int, bool>& mp) {
        if (!root) return nullptr;

        root->left = dfs(root->left, res, mp);
        root->right = dfs(root->right, res, mp);

        if (mp[root->val]) {
            if (root->left && !mp[root->left->val]) res.insert(root->left);
            if (root->right && !mp[root->right->val]) res.insert(root->right);
            res.erase(root); // Remove root from the result set
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, bool> mp;
        for (int val : to_delete) {
            mp[val] = true;
        }

        unordered_set<TreeNode*> res;
        if (!mp[root->val]) {
            res.insert(root);
        }

        dfs(root, res, mp);

        vector<TreeNode*> ans(res.begin(), res.end());
        return ans;
    }
};
