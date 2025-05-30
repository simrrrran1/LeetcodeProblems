class Solution {
public:
    // DFS helper to search for the word starting from board[i][j]
    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& vis, string word, int idx, int row, int col) {
        // If we have matched all characters in the word
        if (idx == word.size()) return true;

        // Boundary checks and character match check
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[idx] || vis[i][j]) 
            return false;

        // Mark current cell as visited
        vis[i][j] = true;

        // Recursively search in all four directions
        bool left  = dfs(board, i - 1, j, vis, word, idx + 1, row, col);
        bool right = dfs(board, i + 1, j, vis, word, idx + 1, row, col);
        bool up    = dfs(board, i, j - 1, vis, word, idx + 1, row, col);
        bool down  = dfs(board, i, j + 1, vis, word, idx + 1, row, col);

        // Backtrack: unmark the visited cell
        vis[i][j] = false;

        // If any direction returns true, word exists
        return left || right || up || down;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        // Visited matrix to avoid revisiting same cell in one DFS path
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        // Try to find the word starting from every cell in the board
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, i, j, vis, word, 0, row, col)) 
                    return true;
            }
        }

        // Word not found in any path
        return false;
    }
};
