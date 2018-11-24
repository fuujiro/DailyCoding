class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3)
            return len;
        int index = 2;
        for(int i = 2; i < len; ++i) {
            if(nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
};