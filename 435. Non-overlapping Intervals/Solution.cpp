class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        } );
        
        int prev = 0;
        int count = 1;

        for(int i=1; i<intervals.size(); i++){
            if(intervals[prev][1] <= intervals[i][0]){
                count += 1;
                prev = i;
            }
        }

        return intervals.size() - count;
    }
};