class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp;
        combine(res, temp, nums, 0);
        return res;
}
    void combine(vector<vector<int> >& res, vector<int>& temp, vector<int>& nums, int begin) {
        res.push_back(temp);
        for(int i = begin; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            combine(res, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};