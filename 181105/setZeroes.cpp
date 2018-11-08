class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> column;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }

        for(int i = 0; i < row.size(); ++i) {
            for(int j = 0; j < n; ++j) {
                matrix[row[i]][j] = 0;
            }
        }

        for(int i = 0; i < column.size(); ++i) {
            for(int j = 0; j < m; ++j) {
                matrix[j][column[i]] = 0;
            }
        }
    }
};