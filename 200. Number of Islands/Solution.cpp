class Solution {
public:
    // Depth-First Search to mark all connected '1's as visited
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
        // Base case: check for out-of-bounds or water or already visited cell
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1')
            return;

        // Mark current land cell as visited
        grid[i][j] = '2';

        // Explore all 4 directions (up, down, left, right)
        dfs(grid, i - 1, j, row, col); // up
        dfs(grid, i + 1, j, row, col); // down
        dfs(grid, i, j - 1, row, col); // left
        dfs(grid, i, j + 1, row, col); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0; // Counter for number of islands

        // Traverse every cell in the grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If a land cell ('1') is found, it starts a new island
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, row, col); // Mark the entire island
                    ans++; // Increment island count
                }
            }
        }

        return ans; // Return total number of islands found
    }
};
