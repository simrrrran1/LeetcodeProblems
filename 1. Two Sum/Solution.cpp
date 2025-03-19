class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){
            int comp = target-nums[i];
            if(mp.find(comp) != mp.end()){
                v[0] = i;
                v[1] = mp[comp];
                break;
            }
            mp[nums[i]] = i;
        }

        return v;
    }
};