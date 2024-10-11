class Solution {
public:
    void twoPointer(vector<int>&nums,int start, int end,int i, vector<vector<int>>&ans){
        while(start<end){
            int sum=nums[i]+nums[start]+nums[end];
            if(sum==0){
                ans.push_back({nums[i],nums[start],nums[end]});
                while(start<end && nums[start]==nums[++start]);
                while(start<end && nums[end]==nums[--end]);
            }else if(sum<0)start++;
            else end--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return {};
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            twoPointer(nums,i+1,n-1,i,ans);
        }
        return ans;
    }
};