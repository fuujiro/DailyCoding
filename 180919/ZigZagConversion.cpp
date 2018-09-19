class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len <= 1 || numRows == 1)
            return s;
        string temp[numRows];
        for(int i = 0; i < numRows; i++)
            temp[i] = "";
        for(int i = 0; i < len; i++) {
            int index = i % (2*numRows-2);
            if(index >= numRows)
                index = 2 * numRows - 2 - index;
            temp[index] += s[i];
        }
        string result = "";
        for(int i = 0; i < numRows; i++)
            result += temp[i];
        return result;
    }
};

