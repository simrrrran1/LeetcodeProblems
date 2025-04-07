class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int row, int col){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == 0) {
            return 1;
        }

        if(grid[i][j] == 2) return 0;

        grid[i][j] = 2;

        int peri = 0;

        peri += dfs(grid, i-1, j, row, col);
        peri += dfs(grid, i+1, j, row, col);
        peri += dfs(grid, i, j-1, row, col);
        peri += dfs(grid, i, j+1, row, col);

        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int perimeter = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    perimeter = dfs(grid, i, j, row, col);
                }
            }
        }

        return perimeter;
    }
};