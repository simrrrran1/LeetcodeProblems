class Solution {
public:
    // Helper DFS function to fill the connected component
    void dfs(vector<vector<int>>& image, int sr, int sc, int row, int col, int color, int target) {
        // Boundary check and base conditions:
        // - Out of bounds
        // - Already filled with the new color
        // - Not equal to the target color
        if (sr < 0 || sc < 0 || sr >= row || sc >= col || image[sr][sc] != target || image[sr][sc] == color)
            return;

        // Fill the current pixel with the new color
        image[sr][sc] = color;

        // Recursively fill all 4 adjacent directions (up, down, left, right)
        dfs(image, sr - 1, sc, row, col, color, target); // up
        dfs(image, sr + 1, sc, row, col, color, target); // down
        dfs(image, sr, sc - 1, row, col, color, target); // left
        dfs(image, sr, sc + 1, row, col, color, target); // right
    }

    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // If the starting pixel already has the new color, no need to proceed
        if (image[sr][sc] == color)
            return image;

        int row = image.size();         // Total number of rows
        int col = image[0].size();      // Total number of columns
        int target = image[sr][sc];     // Color to be replaced

        // Start DFS from the given starting pixel
        dfs(image, sr, sc, row, col, color, target);

        return image; // Return the modified image
    }
};
