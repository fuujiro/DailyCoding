class Solution {
public:
    bool isPalindrome(int x) {
        int a = 0, b = x;
        while(b > 0) {
            a = a * 10 + b % 10;
            b /= 10;
        }
        if(a == x)
            return true;
        else
            return false;
    }
};
