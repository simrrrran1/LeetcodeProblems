class Solution {
public:
    bool helper(vector<vector<int>>& graph, int start, int x, vector<int>& color){
        color[start] = x;
        for(auto& i: graph[start]){
            if(color[i] == -1){
                if(!helper(graph, i, !x, color)){
                    return false;
                }
            }
            else if(color[i] == color[start]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!helper(graph, i, 0, color)){
                    return false;
                }
            }
        }

        return true;
    }
};