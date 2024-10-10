class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        pair<int,int>p;
        p.first=intervals[0][0];
        p.second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(p.second<intervals[i][0]){
                ans.push_back({p.first,p.second});
                p.first=intervals[i][0];
                p.second=intervals[i][1];
            }else{
                p.second=max(intervals[i][1],p.second);
            }
        }
        ans.push_back({p.first,p.second});
        return ans;
    }
};