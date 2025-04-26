class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int start, vector<bool>& vis, stack<int>& s, unordered_set<int>& s1){
        if(vis[start]) return false;
        vis[start] =true;
        s1.insert(start);

        for(auto& i: adj[start]){
            if(!vis[i]){
                if(!dfs(adj, i, vis, s, s1)){
                    return false;
                }
            }else if(s1.find(i) != s1.end()) return false;
        }
        s1.erase(start);
        s.push(start);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        vector<vector<int>> adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        stack<int> s;
        vector<bool> vis(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                unordered_set<int> s1; // to remember current path
                if(!dfs(adj, i, vis, s, s1)){
                    return {};
                }
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};