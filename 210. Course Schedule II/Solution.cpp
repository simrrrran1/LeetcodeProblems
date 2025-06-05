class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int start, vector<bool>& vis, stack<int>& s, unordered_set<int>& s1){
        s1.insert(start);
        vis[start] = true;

        for(auto& i: adj[start]){
            if(!vis[i]){
                if(!dfs(adj, i, vis, s, s1)){
                    return false;
                }
            }else if(s1.count(i)) return false;
        }
        s1.erase(start);
        s.push(start);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> vis(numCourses, false);
        stack<int> s;

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                unordered_set<int> s1;
                if(!dfs(adj, i, vis, s, s1)){
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