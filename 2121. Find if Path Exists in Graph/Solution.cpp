class Solution {
public:
    bool helper(vector<vector<int>>& adj, vector<bool>&vis, int source, int destination){
        if(source == destination) return true;
        vis[source] = true;

        for(auto& i: adj[source]){
            if(!vis[i]){
                if(helper(adj, vis, i, destination)){
                    return true;
                }
            }
        }

        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(n, false);

        return helper(adj, vis, source, destination);
    }
};