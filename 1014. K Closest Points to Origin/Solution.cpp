class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;

        for(int i=0; i<points.size(); i++){
            double dis = sqrt( pow(points[i][0], 2) + pow(points[i][1], 2) );
            pq.push({dis, points[i]});
        } 

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }  

        return ans;
    }
};