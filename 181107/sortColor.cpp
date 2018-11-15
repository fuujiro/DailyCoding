class Solution {
public:
    void sortColors(vector<int>& nums) {
	int n2 = -1, n1 = -1, n0 = -1,n=nums.size();
	for (int i = 0; i < n; i++) {
		if (nums[i] == 0) {
			nums[++n2] = 2;
			nums[++n1] = 1;
			nums[++n0] = 0;
		}
		else if (nums[i] == 1) {
			nums[++n2] = 2;
			nums[++n1] = 1;
		}
		else {
			nums[++n2] = 2;
		}
	}       
}
};