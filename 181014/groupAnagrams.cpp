class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int size = strs.size();
        if(size <= 0) {
            return ans;
        }
        map<string, vector<string>> hashMap;
        for(int i = 0; i < size; ++i) {
            string s = strs[i];
            string t = s;
            sort(t.begin(), t.end());
            map<string, vector<string>>::iterator iter = hashMap.find(t);
            if(iter == hashMap.end()) {
                vetor<string> tv;
                tv.push_back(s);
                hashMap.insert(pair<string, vector<string>> (t, tv));
            } else {
                (iter->second).push_back(s);
            }
        }
        for(map<string, vector<string>>::iterator iter = hashMap.begin(); iter != hashMap.end(); ++iter) {
            vector<string> tV(iter->second);
            sort(tV.begin(), tV.end());
            ans.push_back(tV);
        }
        return ans;
    }
};
