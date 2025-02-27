class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        pair<int,int> p;
        p.first = intervals[0][0];
        p.second = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(p.second < intervals[i][0]){
                ans.push_back({p.first, p.second});
                p.first = intervals[i][0];
                p.second = intervals[i][1];
            }else{
                p.second = max(p.second, intervals[i][1]);
            }
        }
        ans.push_back({p.first, p.second});
        return ans;
    }
};