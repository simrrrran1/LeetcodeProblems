class Solution {
public:
    bool dfs(vector<vector<int>>& adj, stack<int>& s, unordered_set<int>& s1, int i, vector<bool>& vis){
        if(vis[i]) return false;
        s1.insert(i);
        vis[i] = true;

        for(auto& it:adj[i]){
            if(!vis[it]){
                if(!dfs(adj, s, s1, it, vis)){
                    return false;
                }
            }else if(s1.count(it)) return false;
        }

        s1.erase(i);
        s.push(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> vis(numCourses, 0);
        stack<int> s;

        for(int i=0; i<numCourses; i++){
            unordered_set<int> s1;
            if(!vis[i]){
                if(!dfs(adj, s, s1, i, vis)){
                    return {};
                }
            }
        }

        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};