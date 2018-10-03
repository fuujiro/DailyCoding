class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string ss[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.size() == 0)
            return res;
        res.push_back("");
        for(int i = 0; i < digits.size(); ++i) {
            vector<string> tempres;
            string chars = ss[digits[i] - '0'];
            for(int j = 0; j < chars.size(); ++j) {
                for(int k = 0; k < res.size(); ++k)
                    tempres.push_back(res[k] + chars[j]);
            }
            res = tempres;
        }
        return res;
    }
};
