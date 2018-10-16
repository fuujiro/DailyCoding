class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int level = 0, i = 0, curMax = 0, nextMax = 0;
        // 节点下标
        while (curMax - i + 1 > 0) {
            level++;
            // 对当前能走的最大步数范围内的每一步做比较
            for (; i <= curMax; ++i) {
                nextMax = max(nextMax, nums[i] + i);
                // level为所跳的次数
                if (nextMax >= n - 1) return level;
            }
            curMax = nextMax;
        }
        return 0;
    }
};