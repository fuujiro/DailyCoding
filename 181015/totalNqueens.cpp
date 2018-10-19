ass Solution {
public:

    bool can_put(vector<int> &columns,int col)
    {
        for(int i = 0;i < columns.size();i++)
        {
            if(columns[i] == col || abs(col - columns[i]) == abs(columns.size() - i))
                return false;
        }
        return true;
    }
    int queensAnswer(int n,vector<int> &columns,int num)//此处的num指的就是当前遍历的第多少行
    {
        if(num == n) return 1;//执行到此步说明已经当前某个皇后布局符合答案且走到了最后一行，方案数+1
        int total= 0;
        for(int i = 0;i < n;i++)
        {
            if(can_put(columns,i))
            {
                columns.push_back(i);
                total += queensAnswer(n,columns,num+1);//即按照当前的各行皇后位置布局其后几行的皇后布局方案数，num+1表示对num行之后的方案搜索
                columns.pop_back();
            }
        }
        return total;
    }
    int totalNQueens(int n) {
        vector<int> columns;//放置各行皇后所在的列
        if(n == 1)
            return 1;
        else if(n == 2 || n == 3)
            return 0;
        else if(n == 4)
            return 2;
        else
            return queensAnswer(n,columns,0);
    }
};

