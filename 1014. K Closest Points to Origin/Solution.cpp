class Solution {
public:
 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>>pq;
        for(auto i:points){
            int x=i[0];
            int y=i[1];
            double dist=sqrt((x*x)+(y*y));
            pq.push({dist,{x,y}});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};