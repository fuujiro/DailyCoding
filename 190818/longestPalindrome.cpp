class Solution {
public:
    string longestPalindrome(string s) {
        string t = preProcess(s);
        int n = t.size();
        vector<int> p(n,0);
        int c = 0, r = 0;
        for (int i = 0;i < n;i++)
        {
        	if (r > i)
        		p[i] = min(r-i,p[2*c-i]);
        	
        	while (i-1-p[i] >= 0 && i+1+p[i] < n && t[i+1+p[i]] == t[i-1-p[i]])
        		p[i]++;
        		
        	if (i+p[i] > r)
        	{
        		r = i+p[i];
        		c = i;
		}
	}
		
	int max = 0, center = 0;
	for (int i = 0;i < n;i++)
		if (p[i] > max)
		{
			max = p[i];
			center = i;
		}
	return s.substr((center-max)/2,max);
    }
    
private:
	string preProcess(string &s)
	{
		string p = "#";
		for (int i = 0;i < s.size();i++)
			p += s[i], p += '#';  
		return p;
	}
};
