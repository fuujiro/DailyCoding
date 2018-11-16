class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int left=0,right=(rows*cols-1);
        int mid,r,c;
        while(left<=right){
            mid=left+((right-left)>>1);
            r=mid/cols;
            c=mid%cols;
            if(matrix[r][c]==target)
                return true;
            if(matrix[r][c]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};