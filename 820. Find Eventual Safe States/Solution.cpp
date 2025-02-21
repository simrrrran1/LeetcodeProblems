class Solution {
public:

    bool helper(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& backEdges){
        if(backEdges[node]) return true;
        if(visited[node]) return false;

        visited[node] = true;
        backEdges[node] =true;

        for(auto i: graph[node]){
            if(helper(i, graph, visited, backEdges)){
                return true;
            }
        }

        backEdges[node] = false;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<bool> visited(n), backEdges(n);
        for(int i=0; i<n; i++){
            helper(i, graph, visited, backEdges);
        }

        vector<int> safeNodes;
        for(int i=0; i<n; i++){
            if(!backEdges[i]){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;


    }

    //graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    //Output: [2,4,5,6]
};