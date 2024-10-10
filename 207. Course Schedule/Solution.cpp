class Solution {
public:
    bool helper(vector<vector<int>>&graph,vector<int>&v,int start,int end){
        
        if(v[start]==1){
            return true;
        }
        if(!v[start]){
            v[start]=1;
            for(auto &i:graph[start]){
                if(helper(graph,v,i,end)){
                    return true;
                }
            }
        }
        v[start]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> v(numCourses,0);
        int cycleFlag=0;
        for(int i=0;i<numCourses;i++){
            if(!v[i]){
                if(helper(graph,v,i,-1))
                cycleFlag=1;
            }

        }
        return cycleFlag==0?true:false;
    }
};