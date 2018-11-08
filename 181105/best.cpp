static const auto ______ = [](){ 
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool setFirstRowZeros = false;
        bool setFirstColumnZeros = false;
        int rows = matrix.size();
        int columns = rows?matrix[0].size():0;
        
        if (rows == 0 || columns == 0) {
            return;
        }
        
        for(int i=0; i<rows; i++) {
            if(matrix[i][0] == 0) {
                setFirstColumnZeros = true;
                break;
            }
        }
        
        for(int i=0; i<columns; i++) {
            if(matrix[0][i] == 0) {
                setFirstRowZeros = true;
                break;
            }
        }
        
        for(int i=1; i<rows; i++) {
            for(int j=1; j<columns; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<rows; i++) {
            if(matrix[i][0] == 0) {
                for(int j=1; j<columns; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<columns; i++) {
            if (matrix[0][i] == 0) {
                for(int j=1; j<rows; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        if (setFirstColumnZeros) {
            for(int i=0; i<rows; i++) {
                matrix[i][0] = 0;
            }
        }
        
        if (setFirstRowZeros) {
            for(int i=0; i<columns; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};