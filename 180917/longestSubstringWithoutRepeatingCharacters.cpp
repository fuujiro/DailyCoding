class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Max = 0;
        int length = 0;
        int index = 0;
        int start = 0;
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if (!isRepeating(s[i] , temp, index)) {
                length++;
            } else {
                Max = max(length, Max);
                length = temp.length() - index;
                start = start + index + 1;
                temp = s.substr(start, length - 1);
            }
            temp += s[i];
        }
        Max = max(length, Max);
        return Max;
    }
    bool isRepeating(char c, string s, int& index) {
        for (int i = 0; i < s.length(); i++) {
            if (c == s[i]) {
                index = i;
                return true;
            }
        }
        return false;
    }
};
