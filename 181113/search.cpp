class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return false;
        int k = nums[0];
        if(k == target)
            return true;
        int left = 0, right = len - 1;
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            int cur = nums[mid];
            if(target == cur)
                return true;
            if(nums[left] <= cur){
                if(target >= nums[left] && cur > target){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if(target <= nums[right] && target > cur) {
                    left = mid + 1
                } else {
                    right = mid;
                }
            }
        }
        return nums[left] == target;
    }
}