class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal = 0;
    int anti_diagonal = 0;
    int n;
    TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0) {
    }
    
    int move(int row, int col, int player) {
        int point = (player == 1 ? 1 : -1);
        rows[row] += point;
        cols[col] += point;
        if(row == col)
        diagonal += point;
        if(row + col == n-1)
        anti_diagonal += point;
        
        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(anti_diagonal) == n) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */