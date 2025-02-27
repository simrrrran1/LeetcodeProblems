class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int left = 0, right = n - 1;

        // Binary search to find the position to insert newInterval
        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Insert newInterval at the found position
        intervals.insert(intervals.begin() + left, newInterval);


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