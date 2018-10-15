class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        f(res, 0, target, candidates, combination);
        return res;
    }
    void f(vector<vector<int>> &res,int n,int target,vector<int>& candidates,vector<int> &combination) {
        if(!target) {
            res.push_back(combination);
            return;
        }
        if(target < 0)
            return;
        for(int i = n; i < candidates.size() && target >= candidates[i]; ++i) {
            if(n != i && candidates[i] == candidates[i - 1])
                continue;
            combination.push_back(candidates[i]);
            f(res, i + 1, target - candidates[i], candidates, combination);
            combination.pop_back();
        }
    }
};