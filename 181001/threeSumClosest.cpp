static int x = []{ios::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 0;
        int diff = INT_MAX;
        for(int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int temp_sum = nums[i] + nums[left] + nums[right];
                int temp_diff = abs(temp_sum - target);
                if(temp_diff < diff) {
                    diff = temp_diff;
                    closest = temp_sum;
                }
                if(target > temp_sum) {
                    left ++;
                }
                else if(target < temp_sum) {
                    right --;
                }
                else
                    return temp_sum;
            }
        }
        return closest;
    }
};
