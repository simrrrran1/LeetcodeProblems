class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0; // The current range of indices we can reach with the current number of jumps
        int ans = 0;             // Number of jumps made

        // Continue jumping until we've reached or passed the last index
        while (right < nums.size() - 1) {
            int farthest = 0;    // The farthest index we can reach in the next jump

            // Explore all indices in the current range [left, right]
            for (int i = left; i <= right; i++) {
                // Update the farthest we can go from this position
                farthest = max(farthest, i + nums[i]);
            }

            // Prepare for the next jump: update the window
            left = right + 1;    // Move left to start of new range
            right = farthest;   // Move right to the farthest reachable index in next jump

            ans += 1;           // One more jump used
        }

        return ans;             // Total number of jumps needed
    }
};
