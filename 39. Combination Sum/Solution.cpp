class Solution {
public:
    void helper(vector<int>& candidates, int start, int n, int sum, int target, vector<int> v, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        if (sum > target) return;
        for(int i=start; i<n; i++){
            sum += candidates[i];
            v.push_back(candidates[i]);
            helper(candidates, i, n, sum, target, v, ans);
            sum -= candidates[i];
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        helper(candidates, 0, n, 0, target, v, ans);
        return ans;
    }
};