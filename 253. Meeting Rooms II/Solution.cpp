class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n, 0);
        vector<int> end(n, 0);
        for(int i=0; i<n; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int ans = 0;
        int sIdx = 0, eIdx = 0;
        int curr = 0;
        while(sIdx < n && eIdx < n){
            if(start[sIdx] < end[eIdx]){
                curr++;
                sIdx++;
            }
            else {
                curr--;
                eIdx++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};