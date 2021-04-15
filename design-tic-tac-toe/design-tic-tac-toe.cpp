class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector< vector<char> > matrix;
    int rows, cols;
    vector<char> alph{'X', 'O'};
    TicTacToe(int n) {
        matrix.resize(n, vector<char>(n));
        rows = cols = n;
    };
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    
    bool validateRowsAndCols(int player)
    {
        char tmp = alph[player - 1];
        
        for(int i = 0; i < rows; i++)
        {
            int checks = 0;
            for(int j = 0; j < cols; j++)
            {
                if(tmp != matrix[i][j])
                    break;
                checks++;
            }
            
            if(checks == rows)
                return true;
        }
        
        for(int i = 0; i < cols; i++)
        {
            int checks = 0;
            for(int j = 0; j < rows; j++)
            {
                if(tmp != matrix[j][i])
                    break;
                checks++;
            }
            
            if(checks == cols)
                return true;
        }
        
        return false;
    };
    
    bool validateDiagonals(int player)
    {
        int checks = 0;
        char tmp = alph[player - 1];
        
        int sR = 0, sC = 0;
        while(sR < rows && sC < cols)
        {
            if(tmp != matrix[sR][sC])
                break;
            checks++;
            sR++;
            sC++;
        }
        
        if(checks == rows)
            return true;
        
        sR = 0;
        sC = (cols - 1);
        
        checks = 0;
        while(sR < rows && sC >= 0)
        {
            if(tmp != matrix[sR][sC])
                break;
            checks++;
            sR++;
            sC--;
        }
        
        if(checks == rows)
            return true;
        return false;
    }
    
    int move(int row, int col, int player) {
        
        char tmp = alph[player - 1];
        matrix[row][col] = tmp;
        if(validateDiagonals(player) || validateRowsAndCols(player))
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */