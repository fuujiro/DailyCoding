/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: merge.cpp
 * Contributor: fuujiro
 * Date: 12/05/2018
 * Description:
*
================================================================*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
