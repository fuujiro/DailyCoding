class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for(int i = 0; i < t.size(); i++) { 
            m[t[i]] += 1;
        }
        int cnt = 0, l = 0, minl = 0, minsize = s.size() + 1;
        for(int r = 0; r < s.size(); r++) {
            if(m.find(s[r]) != m.end()) {
                if(--m[s[r]] >= 0)
                    ++cnt;
            }
            while(cnt == t.size()) {
                if(r - l + 1 < minsize) {
                    minl = l;
                    minsize = r - l + 1;
                }
                if(m.find(s[l]) != m.end()) {
                    if(++m[s[l]] > 0)
                        --cnt;
                }
                ++l;
            }
        }
        if(minsize > s.size())
            return "";
        return s.substr(minl, minsize);
    }
};