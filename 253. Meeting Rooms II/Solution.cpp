class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n, 0);
        vector<int> end(n, 0);

        for(int i=0; i<intervals.size(); i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        int ans = 0;
        int curr = 0;
        int i=0, j=0;
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        while(i < n && j < n){
            if(start[i] < end[j]){
                i++;
                curr++;
            }else{
                j++;
                curr--;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};