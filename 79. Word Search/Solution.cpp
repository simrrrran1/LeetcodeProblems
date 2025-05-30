class Solution {
public:
    // Helper function to perform DFS and backtracking
    bool helper(vector<vector<char>>& board, int i, int j, string word, int idx, int n, int m) {
        // If all characters are matched
        if (idx == word.size()) return true;

        // Boundary checks and mismatch check
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[idx]) return false;

        // Temporarily mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '.';

        // Explore all four directions
        int left  = helper(board, i - 1, j, word, idx + 1, n, m);
        int right = helper(board, i + 1, j, word, idx + 1, n, m);
        int up    = helper(board, i, j - 1, word, idx + 1, n, m);
        int down  = helper(board, i, j + 1, word, idx + 1, n, m);

        // If any direction returns true, word exists
        if (left || right || up || down) return true;

        // Backtrack: restore the original character
        board[i][j] = temp;

        return false;
    }

    // Main function to search the word in the board
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // Try starting DFS from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (helper(board, i, j, word, 0, n, m)) return true;
            }
        }

        // If no valid path is found
        return false;
    }
};
