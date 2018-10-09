class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len -1;
        while(left <= right) {
            int ave = (left + right) / 2;
            if(nums[ave] > target)
                right = ave - 1;
            else if(nums[ave] < target)
                left = ave + 1;
            else {
                return ave;
            }
        }
        return left;
    }
};

