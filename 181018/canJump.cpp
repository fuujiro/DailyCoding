class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
			return false;
        int size = nums.size();
        int far = -1;
        for(int i = 0; i < size; ++i) {
            if(nums[i] > far)
                far = nums[i];
            if(far >= size - 1 - i)
                return true;
            if(far == 0)
                break;
            far--;
        }
        return false;
    }
};
