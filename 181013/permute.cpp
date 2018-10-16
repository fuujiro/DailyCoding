class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        permute(nums, 0, permutations);
        return permutations;
    }
    
private:
    void permute(vector<int> &nums, int begin, vector<vector<int>> &permutations) {
        if (begin == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[i], nums[begin]);
            permute(nums, begin + 1, permutations);
            swap(nums[i], nums[begin]);
        }
    }
};