class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int> (n));
        if(!n)
            return result;
        int row = n;
        int col = n;
        vector<vector<int>> dire = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int select[2] = {col, row - 1};
        int cur[2] = {0, -1};
        int dir = 0;
        int k = 1;
        while(select[dir%2]) {
            int steps = select[dir%2];
            for(int i = 0; i < steps; ++i) {
                cur[0] += dire[dir][0];
                cur[1] += dire[dir][1];
                result[cur[0]][cur[1]] = k++;
            }
            select[dir%2]--;
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
