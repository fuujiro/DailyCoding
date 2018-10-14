class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        if (n == 1) return "1";
        string res = "1";
        while (--n) //循环n次从头开始生成第二个字符数组
        {
            string cur = "";
            for (int i = 0; i < res.size(); i++)    //cheack all digits in the res
            {
                int count = 1; //we have at least 1 occourence of each digit
                while ((i + 1 < res.size()) && (res[i] == res[i + 1])) //i+1<res.size()防止下标溢出
                {
                    count++;
                    i++;
                }
                cur += std::to_string(count) + res[i];
            }
            res = cur;
            cur.clear();//释放辅助变量
        }
        return res;

    }
};
