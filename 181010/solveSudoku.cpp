static const auto ____ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokudfs(board);
    }

    bool solveSudokudfs(vector<vector<char> > &board)  
    {  
        for(int i = 0; i < 9; i++)  
            for(int j = 0; j < 9; j++)  
            {  
                if(board[i][j] == '.')  
                {  
                    for(int k = 1; k <= 9; k++)  
                    {  
                        board[i][j] = '0' + k;  
                        if(isValid(board,i,j) && solveSudokudfs(board))  
                            return true;  
                        //回溯
                        board[i][j] = '.';  
                    }  
                    return false;  
                }  
            }  
        return true;  
    }  
    bool isValid(vector<vector<char> > &board, int row, int col) {  
        int i,j;  
        //查看同一列是否有重复
        for(i = 0; i < 9; i++)  
            if(i != row && board[i][col] == board[row][col])  
                return false;  
        //查看同一行是否有重复
        for(j = 0; j < 9; j++)  
            if(j != col && board[row][j] == board[row][col])  
                return false;  
        //小九宫格内是否有重复, x,y 是小9宫格的左上角的坐标
        int x = row/3*3;  
        int y = col/3*3;  
        for(i = 0; i < 3; i++)  
            for(j = 0; j< 3; j++)  
                if(x+i != row && y+j != col && board[x+i][y+j] == board[row][col])  
                    return false;  
        return true;  
    }  
};

