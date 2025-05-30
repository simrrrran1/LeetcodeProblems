class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& vis, string word, int idx, int row, int col){
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i >= row || j >= col || word[idx] != board[i][j] || vis[i][j]) return false;

        vis[i][j] = true;
        bool left = dfs(board, i-1, j, vis, word, idx + 1, row, col);
        bool right = dfs(board, i+1, j, vis, word, idx + 1, row, col);
        bool up = dfs(board, i, j-1, vis, word, idx + 1, row, col);
        bool down = dfs(board, i, j+1, vis, word, idx + 1, row, col);
        vis[i][j] = false;
        
        return left || right || up || down;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(dfs(board, i, j, vis, word, 0, row, col)) return true;
            }
        }
        return false;
    }
};