ass Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> queens(n, string(n, '.'));
		vector<int> width_o(n, 1), cross_lr(2 * n - 1, 1), cross_rl(2 * n - 1, 1);
		backtrack(result, queens, 0, width_o, cross_lr, cross_rl, n);
		return result;
	}

	void backtrack(vector<vector<string>> &result, vector<string> &queens,
		int cur_height, vector<int> &width_o, vector<int> &cross_lr,
		vector<int> &cross_rl, int n)
	{
		if (cur_height == n)
		{
			result.push_back(queens);
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (width_o[i] == 1 && cross_lr[n - (cur_height - i) - 1] == 1 &&
				cross_rl[cur_height + i] == 1)
			{
				width_o[i] = 0;
				cross_lr[n - (cur_height - i) - 1] = 0;
				cross_rl[cur_height + i] = 0;
				queens[cur_height][i] = 'Q';
				backtrack(result, queens, cur_height + 1, width_o, cross_lr, cross_rl, n);
				queens[cur_height][i] = '.';
				width_o[i] = 1;
				cross_lr[n - (cur_height - i) - 1] = 1;
				cross_rl[cur_height + i] = 1;
			}
		}
	}
};
