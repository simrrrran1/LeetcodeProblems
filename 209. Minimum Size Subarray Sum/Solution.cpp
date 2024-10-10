class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0,minLen=INT_MAX,sum=0;
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                minLen=min(right-left+1,minLen);
                sum-=nums[left];left++;
            }
            right++;
        }
        return minLen==INT_MAX?0:minLen;
    }
};