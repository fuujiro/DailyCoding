class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	    int sum = 0;
        int Max = INT_MIN;
        for(int i : nums) {
            sum = max(i, sum + i);
            Max = max(Max, sum);
        }
        return Max;
    }
};
