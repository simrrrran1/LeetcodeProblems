class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();        // Number of rows
        int col = matrix[0].size();     // Number of columns

        int i = 0, j = col - 1;         // Start from the top-right corner

        // Loop until we are out of matrix bounds
        while(i < row && j >= 0){
            if(matrix[i][j] > target) {
                // If current element is greater than target, move left
                j--;
            }
            else if(matrix[i][j] < target) {
                // If current element is smaller than target, move down
                i++;
            }
            else {
                // Found the target
                return true;
            }
        }

        // Target not found
        return false;
    }
};
