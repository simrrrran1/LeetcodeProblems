class Solution {
public:
    void helper(vector<int>& candidates, int start, vector<vector<int>>& ans, vector<int> v, int target){
        if(target < 0) {
            return;
        }
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i = start; i<candidates.size(); i++){
            v.push_back(candidates[i]);
            helper(candidates, i, ans, v, target-candidates[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates, 0, ans, v, target);
        return ans;
    }
};