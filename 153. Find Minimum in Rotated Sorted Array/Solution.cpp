class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=nums[0];
        while(i<=j){
            if(nums[i]<nums[j]){
                ans=min(ans,nums[i]);break;
            }
            int mid=i+(j-i)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]>=nums[i])i=mid+1;
            else j=mid-1;
        }
        return ans;
    }
};