class Solution {
public:
    void fnc(int n, int start, int k, vector<int>& v, vector<vector<int>>& ans){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }

        for(int i=start; i<=n; i++){
            v.push_back(i);
            fnc(n, i+1, k, v, ans);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;

        fnc(n, 1, k, v, ans);
        return ans;
    }
};