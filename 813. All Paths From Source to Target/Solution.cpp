class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<vector<int>>&ans, vector<int> v, int start, int end){
        if(start == end){
            v.push_back(end);
            ans.push_back(v);
            return;
        }

        vis[start] = true;
        v.push_back(start);

        for(auto& i: graph[start]){
            if(!vis[i]){
                dfs(graph, vis, ans, v, i, end);
            }
        }
        vis[start] = false;
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false);

        vector<vector<int>> ans;

        dfs(graph, vis, ans, {}, 0, n-1);

        return ans;
    }
};