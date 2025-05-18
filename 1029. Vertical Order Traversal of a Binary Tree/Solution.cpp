class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Nested map: column -> row -> multiset of values
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {row, col}}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            nodes[col][row].insert(node->val);

            if (node->left) q.push({node->left, {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;
        for (auto& colPair : nodes) {
            vector<int> colValues;
            for (auto& rowPair : colPair.second) {
                colValues.insert(colValues.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(colValues);
        }

        return ans;
    }
};
