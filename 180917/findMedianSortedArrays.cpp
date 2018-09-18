class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {

        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = nums1.size();
        int n = nums2.size();
        vector<int>   v;
		v.insert(v.end(),   nums1.begin(),   nums1.end());
		v.insert(v.end(),   nums2.begin(),   nums2.end());



        sort(v.begin(),v.end());

        double median=(double) ((n+m)%2? v[(n+m)/2]:(v[(n+m-1)/2]+v[(n+m)/2])/2.0);



        return median;
    }
};
