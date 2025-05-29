class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), boards(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int x = board[i][j] - '0';

                if(rows[i].count(x) || cols[j].count(x) || boards[i/3 + j/3 * 3].count(x))
                    return false;
                rows[i].insert(x);
                cols[j].insert(x);
                boards[i/3 + j/3 * 3].insert(x);
            }
        }
        return true;
    }
};