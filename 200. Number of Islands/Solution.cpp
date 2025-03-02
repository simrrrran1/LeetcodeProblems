class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]!='1')return;
        grid[row][col] = '2';

        dfs(grid, row-1, col, m, n);
        dfs(grid, row+1, col, m, n);
        dfs(grid, row, col-1, m, n);
        dfs(grid, row, col+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m =grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};