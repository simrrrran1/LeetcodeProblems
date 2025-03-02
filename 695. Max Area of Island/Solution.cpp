class Solution {
public:

    int dfs(vector<vector<int>>& grid, int row, int col, int n, int m){
        if(row<0 || row>=n || col<0 || col>=m || !grid[row][col])return 0;

        grid[row][col] = 0;

        return 1 + dfs(grid, row+1, col, n, m) + dfs(grid, row-1, col, n, m) + dfs(grid, row, col+1, n, m)+ dfs(grid, row, col-1, n, m);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j])
                ans = max(ans, dfs(grid, i, j, n, m));
            }
        }

        return ans;
    }
};