class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int start, vector<bool>& vis, unordered_set<int>& s){
        vis[start] = true;
        s.insert(start);

        for(auto& i: adj[start]){
            if(!vis[i]){
                if(!dfs(adj, i, vis, s))
                    return false;
            }else if(s.count(i)){
                return false;
            }
        }
        s.erase(start);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> vis(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                unordered_set<int> s;
                if(!dfs(adj, i, vis, s))
                    return false;
            }
        }
        return true;
    }
};