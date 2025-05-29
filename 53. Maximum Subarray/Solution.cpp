class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], curr = 0;
        for(int i=0; i<nums.size(); i++){
            curr += nums[i];
            sum = max(sum, curr);
            if(curr < 0)curr = 0;
        }
        return sum;
    }
};