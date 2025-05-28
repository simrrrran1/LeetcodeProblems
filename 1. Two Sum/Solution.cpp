class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()){
                ans[0] = i;
                ans[1] = mp[complement];
                break;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};