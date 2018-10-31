class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0, k, l; i < words.size(); i += k) {
            for(k = l = 0; i + k < words.size() && l + words[i+k].size() <= maxWidth - k; k++) //L-k因为每一个单词都有一个空格，l是一行中字符的长度
                l += words[i+k].size();
            string tmp = words[i];
            for(int j = 0; j < k - 1; j++) {
                if(i + k >= words.size()) tmp += " ";//最后一行，只加一个空格
                else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');//不是最后一行，补齐空格，最左边(L - l) % (k - 1)个单词后要比之后的多一个空格
                tmp += words[i+j+1];
            }
            tmp += string(maxWidth - tmp.size(), ' ');//最后一行，末尾补空格
            res.push_back(tmp);
        }
        return res;
    }
};
