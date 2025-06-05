class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize minimum and maximum product ending at current position
        int minPro = 1;
        int maxPro = 1;

        // Initialize the answer with the maximum element (to handle single negative or zero)
        int ans = *max_element(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            // If the current number is 0, reset both minPro and maxPro
            // because the product cannot include any number before this
            if(nums[i] == 0) {
                minPro = 1;
                maxPro = 1;
                continue;
            }

            // Store previous minPro in a temporary variable before updating
            int temp = minPro;

            // Calculate new minPro by considering:
            // 1. current number alone
            // 2. product of current number with previous minPro
            // 3. product of current number with previous maxPro
            minPro = min(min(minPro * nums[i], maxPro * nums[i]), nums[i]);

            // Calculate new maxPro using the same logic
            maxPro = max(max(maxPro * nums[i], temp * nums[i]), nums[i]);

            // Update answer with the maximum product found so far
            ans = max(ans, maxPro);
        }

        return ans;
    }
};
