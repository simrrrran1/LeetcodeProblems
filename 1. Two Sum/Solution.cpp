class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //keep target-nums[i] track in map for better search
        unordered_map<int,int> mp; 

        for(int i=0;i<nums.size();i++){
            int k = target-nums[i];
            // to avoid repetition of solution, implemented mp[nums[i]]!=i
            if(mp.find(k)!=mp.end()){
                return {mp[k],i};
            }
            mp[nums[i]]=i;
        }

        return {};
    }
};