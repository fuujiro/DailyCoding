class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        if(nums.size() == 0 || target < nums[left] || target > nums[right])
            return result;
        while(left < right) {
            int ave = (left + right) / 2;
            if(nums[ave] > target)
                right = ave - 1;
            else if(nums[ave] < target)
                left = ave + 1;
            else {
                left = ave;
                right = ave;
                while(left - 1 >= 0 && nums[left - 1] == target)
                    left --;
                while(right + 1 < nums.size() && nums[right + 1] == target)
                    right++;
                break;
            }
        }
        if(nums[left] == target) {
            result[0] = left;
            result[1] = right;
        }
        return result;
    }
};
