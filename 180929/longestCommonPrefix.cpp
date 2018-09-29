class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cm = "";
        int cm_i = 0;
        int slen = strs.size();
        if(slen == 0)
            return cm;
        if(slen == 1)
            return strs[0];
        while(true) {
            char label = strs[0][cm_i];
            for(int i = 1; i < slen; ++i) {
                if(cm_i >= strs[i].size() || strs[i][cm_i] != label)
                    return cm;
            }
            cm += label;
            cm_i++;
        }
        return cm;
    }
};
