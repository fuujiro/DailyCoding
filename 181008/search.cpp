class Solution {
public:

    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = (l + h) >> 1;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                l = mid + 1;
            else
                h = mid;
        }
        return l == h && nums[l] == target ? l : -1;
    }
};
