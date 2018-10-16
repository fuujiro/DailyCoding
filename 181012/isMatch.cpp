class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int ppos=0;
        int spos=0;
        int star=-1;//找到的'*'的下标
        int match;
        while(spos<s.size())
        {
           if(ppos<p.size()&&(s[spos]==p[ppos]||p[ppos]=='?'))//当前字符匹配
           {
               spos++;
               ppos++;
           }
           else if(ppos<p.size()&&p[ppos]=='*')//当前字符不匹配 当前p[ppos]=‘×’
           {
               match=spos;
               star=ppos++;
           }
           else if(star>=0)//当前字符不匹配 当前p[ppos]！=‘×’ 前一个模式串是'*'
           {
               ppos=star+1;
               spos=++match;
           }
           else
                return false;
        }
        while(ppos<p.size()&&p[ppos]=='*') ppos++;
        return ppos==p.size();
    }
};