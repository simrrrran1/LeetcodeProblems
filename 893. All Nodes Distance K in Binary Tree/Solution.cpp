#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */


class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& mp) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                mp[node].push_back(node->left);
                mp[node->left].push_back(node);
                q.push(node->left);
            }
            if (node->right) {
                mp[node].push_back(node->right);
                mp[node->right].push_back(node);
                q.push(node->right);
            }
        }
    }

    void dfs(TreeNode* node, int k, unordered_set<TreeNode*>& visited, unordered_map<TreeNode*, vector<TreeNode*>>& mp, vector<int>& res) {
        if (!node || visited.count(node)) return;
        visited.insert(node);
        if (k == 0) {
            res.push_back(node->val);
            return;
        }
        for (auto neighbor : mp[node]) {
            dfs(neighbor, k - 1, visited, mp, res);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        buildGraph(root, mp);
        unordered_set<TreeNode*> visited;
        vector<int> res;
        dfs(target, k, visited, mp, res);
        return res;
    }
};
