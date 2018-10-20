ass Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        drt = vector<vector<int>>{{0,1},{1,0},{-1,0},{0,-1}};   //四个方向
        mark = vector<vector<bool>>(100,vector<bool>(100,false));
        ret.clear();
        if(!matrix.size() || !matrix[0].size())
            return ret;
        dfs(matrix, 0, 0, -1);//这里取-1是为了能从(0,0)开始。
        return ret;
    }

    void dfs(vector<vector<int>> & matrix, int direct, int x, int y)
    {
        for(int i = 0; i < 4; ++i){
            int j = (direct + i) % 4;
            int tx = x + drt[j][0];
            int ty = y + drt[j][1];
            if(tx >= 0 && tx < matrix.size() &&
                ty >= 0 && ty < matrix[0].size() &&
                mark[tx][ty] == false){
                mark[tx][ty] = true;
                ret.push_back(matrix[tx][ty]);
                dfs(matrix, j, tx, ty);
            }
        }
    }

private:
    vector<vector<int>> drt;
    vector<vector<bool>> mark;
    vector<int> ret;
};
