/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: merge_best.cpp
 * Contributor: fuujiro
 * Date: 12/05/2018
 * Description:
*
================================================================*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--; n--;
        for(int insertIndex = nums1.size()-1; insertIndex >= 0; insertIndex--) {
            if (n < 0 || (m >= 0 && nums1[m] > nums2[n])) {
                nums1[insertIndex] = nums1[m--];
            } else {
                nums1[insertIndex] = nums2[n--];
            }
        }
    }
};

static int desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
