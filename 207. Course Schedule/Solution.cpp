class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, unordered_set<int>& s){
        s.insert(i);
        vis[i] = true;

        for(auto& it: adj[i]){
            if(!vis[it]){
                if(!dfs(it, adj, vis, s))
                    return false;
            } else if(s.count(it)) return false;
        }
        s.erase(i);
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
                if(!dfs(i, adj, vis, s))
                    return false;
            }
        }

        return true;
        
    }
};