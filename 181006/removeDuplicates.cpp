class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        vector<int>::iterator nums_end_it = unique(nums.begin(),nums.end());
        return nums_end_it - nums.begin();
    }
};
