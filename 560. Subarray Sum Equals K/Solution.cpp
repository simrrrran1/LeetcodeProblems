class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=1;//assumed that there always exist a empty prefix with zero sum
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};