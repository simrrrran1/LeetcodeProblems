class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& colour){
        for(auto& i: graph[node]){
            if(colour[i] == -1){
                colour[i] = 1-colour[node];
                if(!dfs(graph, i, colour)){
                    return false; 
                }
            }
            else if(colour[i] == colour[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i=0; i<n; i++){
            if(colour[i] == -1){
                colour[i] = 1;
                if(!dfs(graph, i, colour)){
                    return false; 
                }
            }
        }
        return true;
    }
};