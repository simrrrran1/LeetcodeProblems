class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0; // The farthest index we can reach at any point

        // Iterate through each position
        for (int i = 0; i < nums.size(); i++) {
            // If the current index is beyond the farthest reachable, we can't continue
            if (i > farthest) return false;

            // Update the farthest index we can reach from here
            farthest = max(farthest, i + nums[i]);
        }

        // If we never hit a dead end, we can reach the end
        return true;
    }
};
