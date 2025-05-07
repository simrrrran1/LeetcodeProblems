class Solution {
public:
    bool isSafe(int r, int c, vector<string>& v){
        for(int i=r-1; i>=0; i--){
            if(v[i][c] == 'Q') return false;
        }
        for(int i=r-1 , j=c+1; i>=0 && j<v.size(); i--, j++){
            if(v[i][j] == 'Q') return false;
        }

        for(int i=r-1 , j=c-1; i>=0 && j>=0; i--, j--){
            if(v[i][j] == 'Q') return false;
        }
        return true;

    }
    void dfs(int r, vector<string>& v, vector<vector<string>>& ans){
        if(r == v.size()){
            ans.push_back(v);
            return;
        }

        for(int c=0; c<v.size(); c++){
            if(isSafe(r, c, v)){
                v[r][c] = 'Q';
                dfs(r+1, v, ans);
                v[r][c] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n, string(n,'.'));
        dfs(0, v, ans);
        return ans;
    }
};