class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
            if(board.empty()){
                        return false;
                    }
            m = board.size();
            n = board[0].size();
            for(int i = 0; i<m; i++){
                        for(int j = 0; j<n; j++){
                                        if(Search(board, word.c_str(), i, j)){
                                                            return true;
                                                        }
                                    }
                    }
            return false;
        }
    private:
    int m;
    int n;
    bool Search(vector<vector<char>>& board, const char* w, int i, int j){
            if(i<0 || j<0  || i>= m || j>=n || board[i][j] == '\0' || *w!=board[i][j]){
                        return false;
                    }
            if(*(w+1) == '\0'){
                        return true;
                    }
            char t = board[i][j];
            board[i][j] = '\0';
            if(Search(board, w+1, i-1, j) || Search(board, w+1, i+1, j) || Search(board, w+1, i, j+1) || Search(board, w+1, i, j-1)){
                        return true;
                    }
            board[i][j] = t;
            return false;
        }
};
