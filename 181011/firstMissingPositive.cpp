class Solution {
public:
    int firstMissingPositive (vector<int>& nums) {
        vector<int>::iterator it;
        int rel = 1;
        int i = 1;
        for(i = 1; i <= nums.size(); ++i) {
            it = find(nums.begin(), nums.end(), i);
            if(it == nums.end()) {
                rel = i;
                break;
            } else if(i == nums.size()) {
                rel = i + 1;
            }
        }
        return rel;
    }
};
