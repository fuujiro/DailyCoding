class Solution {
public:
    vector<vector<int> > combine (int n, int k) {
        vector<vector<int> > res;
        vector<int> tmpres;
        helper(1, n, k, tmpres, res);
        return res;
    }

    void helper(int left, int right, int k, vector<int> &tmpres, vector<vector<int> > &res) {
        if(right - left + 1 < k)
            return;
        if(k == 0) {
            res.push_back(tmpres);
            return;
        }
        tmpres.push_back(left);
        helper(left + 1, right, k - 1, tmpres, res);
        tmpres.pop_back();
        helper(left + 1, right, k, tmpres, res);
    }
};
