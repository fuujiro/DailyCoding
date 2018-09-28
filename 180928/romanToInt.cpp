class Solution {
public:
    int romanToInt(string s) {
        map<char, int> maps;
        maps['I'] = 1;
        maps['V'] = 5;
        maps['X'] = 10;
        maps['L'] = 50;
        maps['C'] = 100;
        maps['D'] = 500;
        maps['M'] = 1000;
        int num = maps[s.at(0)];
        for(int i =  1; i < s.size(); ++i) {
            if(maps[s.at(i)] > maps[s.at(i-1)])
                num += maps[s.at(i)] - 2 * maps[s.at(i-1)];
            else
                num += maps[s.at(i)];
        }
	return num;
    }
};
