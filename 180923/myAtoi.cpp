class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        long long max = ( 1 << 31) - 1;
        long long min = 0 - (1 << 31);
        bool sign = 0;
        bool start = 0;
        int len = str.size();
        for(int i = 0; i < len && result <= max; ++i) {
            if(start == 0) {
                if(str[i] == ' ') {
                    continue;
                } else if(str[i] == '-') {
                    sign = 1;
                    start = 1;
                } else if(str[i] == '+') {
                    start = 1;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    start = 1;
                    result = result * 10 + (str[i] - '0');
                } else {
                    break;
                }
            } else {
                if(str[i] >= '0' && str[i] <= '9') {
                    result = result * 10 + (str[i] - '0');
                } else {
                    break;
                }
            }
        }
        result *= (sign)?-1:1;
	    if(result > max) {
	        return max;
        } else if (result < min) {
            return min;
        }
        return result;
    }
};
