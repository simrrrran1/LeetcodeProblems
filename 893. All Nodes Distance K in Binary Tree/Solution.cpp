class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        vector<int> ans;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int curr = 0;

        while (!q.empty()) {
            if (curr == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && vis.find(node->left) == vis.end()) {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if (node->right && vis.find(node->right) == vis.end()) {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if (parent.find(node) != parent.end() && vis.find(parent[node]) == vis.end()) {
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
            curr++;
        }

        return ans;
    }
};