class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int target = 0;

        //sort
        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i-1]) {
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {
                    if(j - 1 > i && nums[j] == nums[j-1]) {
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k+1]) {
                        --k;
                    } else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) {
                            --k;
                        } else if (sum < target) {
                            ++j;
                        } else {
                            ans.push_back({nums[i],nums[j],nums[k]});
                            ++j, --k;
                        }
                    }
                }
            }
        }
        return ans;
    }
};