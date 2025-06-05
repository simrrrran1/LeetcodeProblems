class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // Step 1: Fill ans[i] with the product of all elements to the left of i
        // Initially, there's no element to the left of index 0, so set ans[0] = 1
        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1]; 
            // ans[i] = product of nums[0] * ... * nums[i-1]
        }

        // Step 2: Multiply ans[i] with the product of all elements to the right of i
        int x = 1; // x holds the running product of elements to the right
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= x;  // multiply left product (already in ans[i]) by right product (x)
            x *= nums[i]; // update x to include nums[i] for next iteration
        }

        return ans;
    }
};
