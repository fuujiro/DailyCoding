class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> vi(num1.size() + num2.size(), 0); // 初始化size()个0
        for(int i = 0; i < num1.size(); ++i) {
            for(int j = 0; j < num2.size(); ++j) {
                vi[i + j] += (num1[num1.size() - 1 - i] - '0') * (num2[num2.size() - 1 - j] - '0');
            }
        }
        for(int i = 0, c = 0; i < vi.size(); ++i) {
            int num = vi[i] + c;
            vi[i] = num % 10;
            c = num / 10;
        }
        string s = "";
        int i = vi.size();
        while(-- i >= 0 && vi[i] == 0);
        if(i < 0)
            s = "0";
        else {
            for( ; i >= 0; --i) {
                s += vi[i] + '0';
            }
        }
        return s;
    }
};
