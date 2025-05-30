class Solution {
public:
    // Helper function to perform backtracking
    void fnc(int n, int start, int k, vector<int>& v, vector<vector<int>>& ans) {
        // Base case: if current combination has k elements, store it
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }

        // Try each number from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            v.push_back(i);                  // Choose the current number
            fnc(n, i + 1, k, v, ans);        // Recurse with next start
            v.pop_back();                    // Backtrack to explore other options
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;     // To store the final combinations
        vector<int> v;               // Current combination being built

        fnc(n, 1, k, v, ans);        // Start from number 1
        return ans;
    }
};
