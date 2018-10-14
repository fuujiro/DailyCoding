class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    int nums_len;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;
        nums_len = candidates.size();
        dfs(0, 0, target, candidates);
        return res;
    }

    void dfs(int start, int sum, int target, vector<int> candidates) {
        if(sum == target) {
            res.push_back(ans);
            return;
        } else if (sum > target) {
            return;
        } else {
            for(int i = start; i < nums_len; i++) {
                ans.push_back(candidates[i]);
                dfs(i, sum + candidates[i], target, candidates);
                ans.pop_back();
            }
        }
    }
};
