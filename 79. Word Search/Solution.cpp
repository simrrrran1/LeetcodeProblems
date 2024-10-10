class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<int>ans;
        vector<list<int>> adj(n);
        vector<int>degree(n,0);
        for(auto i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>leaves;
        for(int i=0;i<degree.size();i++){
            if(degree[i]==1)leaves.push(i);
        }
        int remainder=n;
        while(remainder>2){
            int k=leaves.size();
            remainder-=k;
            for(int i=0;i<k;i++){
                int leaf=leaves.front();
                leaves.pop();
                for(auto& j:adj[leaf]){
                    if(--degree[j]==1)leaves.push(j);
                }
            }
        }
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};