class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        long long max = (1 << 31) - 1;
        long long min = 0 - (1 << 31);
        while(x) {
            result = result * 10 + x % 10;
                x = x / 10;
        }
	return result > max || result < min?0:result;
    }
};
