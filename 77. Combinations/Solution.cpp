class Solution {
public:
    void helper(int n, int start, int k, vector<vector<int>>& ans, vector<int> v){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        for(int i=start; i<=n; i++){
            v.push_back(i);
            helper(n, i+1, k, ans, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(n, 1, k, ans, v);
        return ans;
    }
};