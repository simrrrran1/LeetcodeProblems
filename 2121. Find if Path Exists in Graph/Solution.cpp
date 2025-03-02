class Solution {
public:
    bool dfs(vector<int>&vis, vector<vector<int>>& adjList, int start, int end){
        if(start == end) return true;
        vis[start] = 1;
        for(auto &i:adjList[start]){
            if(!vis[i]){
                if(dfs(vis, adjList, i, end))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        return dfs(vis, adjList, source, destination);

    }
};