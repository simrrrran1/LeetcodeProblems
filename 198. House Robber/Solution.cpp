class Solution {
public:
    int rob(vector<int>& nums) {
        // rob1: max amount robbed from houses up to two steps back
        // rob2: max amount robbed from houses up to one step back
        int rob1 = 0, rob2 = 0;
        int ans = 0;

        // Iterate through each house
        for(int i = 0; i < nums.size(); i++) {
            // Decide: rob current house + rob1 (2 houses back) OR skip and take rob2 (1 house back)
            ans = max(rob2, nums[i] + rob1);

            // Shift rob1 and rob2 forward for next iteration
            rob1 = rob2;
            rob2 = ans;
        }

        // rob2 holds the max profit possible after considering all houses
        return rob2;
    }
};
