class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> v, int idx, int n){
        if(idx == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        helper(nums, ans, v, idx+1, n);
        v.pop_back();
        helper(nums, ans, v, idx+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(nums, ans, v, 0, nums.size());
        return ans;
    }
};