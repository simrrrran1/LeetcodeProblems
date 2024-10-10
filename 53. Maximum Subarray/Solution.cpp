class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN,ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            sum=max(sum,ans);
            if(ans<0)ans=0;
        }
        return sum;
    }
};