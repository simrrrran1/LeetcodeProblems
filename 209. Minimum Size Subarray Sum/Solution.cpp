class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i:nums) sum += i;

        if(target > sum) return 0;

        int left = 0, right = 0, x = 0, ans = INT_MAX;

        while(right < n){
            x += nums[right];
            while(x >= target){
                ans = min(ans, right - left + 1);
                x -= nums[left];
                left++; 
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};