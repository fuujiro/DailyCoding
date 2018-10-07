class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i = 0;i<haystack.size();i++){
            if((i+needle.size())>haystack.size()) return -1;
            if(haystack[i] == needle[0]){
                int j ;
                for(j = 1;j<needle.size();j++){
                    if(needle[j] != haystack[i+j]) break;
                }
                if(j == needle.size()) return i;
            }
        }
        return -1;
    }
};
