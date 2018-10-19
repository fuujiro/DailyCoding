class Solution {
public:
    double myPow(double x, int n) {
    	double ans = 1;
    	unsigned long long p;
    	if (n < 0) {
    		p = -n;
    		x = 1 / x;
    	} else {
    		p = n;
    	}
	while (p) {
		//判断二进制p末位是否为1
		if (p & 1)
			ans *= x;
		x *= x;
		//p右移1位
		p >>= 1;
	}
	return ans;
    }
};
