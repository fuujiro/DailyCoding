class Solution {
    void permute(vector<vector<int>>& res, vector<int>& nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_map<int, int> duplicate;
        for(int i = start; i < nums.size(); ++i) {
            if(duplicate.count(nums[i]) > 0) {
                continue;
            } else {
                duplicate[nums[i]]++;
            }
            swap(nums[i], nums[start]);
            permute(res, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permute(res, nums, 0);
        return res;
    }
};