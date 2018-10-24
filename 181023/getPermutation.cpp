class Solution {
public:
    string getPermutation(int n, int k) {
        string str = string("123456789").substr(0, n);
        string res(n, ' ');
        for(int i = 0; i < n; ++i)
            res[i] = helper(str, k);
        return res;
    }
    char helper(string &s, int &k) {
        int tmp = factorial(s.size() - 1), i = (k - 1) / tmp;
        char res = s[i];
        s.erase(i, 1);
        k -= i * tmp;
        return res;
    }
    int factorial(int n) {
        int res = 1;
        for(int i = 2; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
};