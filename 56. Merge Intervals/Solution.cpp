class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        pair<int, int> p;
        sort(intervals.begin(), intervals.end());
        p.first = intervals[0][0];
        p.second = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] > p.second){
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