class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n, 0);  // Stores all start times
        vector<int> end(n, 0);    // Stores all end times

        // Extract start and end times from the intervals
        for (int i = 0; i < intervals.size(); i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        // Sort the start and end times separately
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int ans = 0;   // Maximum rooms needed at any point
        int curr = 0;  // Current rooms in use
        int i = 0, j = 0;

        // Process all meetings in chronological order
        while (i < n && j < n) {
            if (start[i] < end[j]) {
                // A meeting is starting before the earliest one ends -> need an extra room
                curr++;
                i++;
            } else {
                // A meeting has ended before the next one starts -> free up a room
                curr--;
                j++;
            }
            // Track the maximum number of rooms in use
            ans = max(ans, curr);
        }

        return ans;  // Minimum number of meeting rooms required
    }
};
