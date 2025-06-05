class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i=1; i<row; i++) grid[i][0] += grid[i-1][0];

        for(int i=1; i<col; i++) grid[0][i] += grid[0][i-1];

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];


    }
};

//[1, 2, 3],
//[4, 5, 6]

//[1 , 3 , 6]
//[5 , 5 , 6]

//[1, 3, 6]
//[5, 8, 6]

//[1, 3, 6]
//[5, 8, 12]
