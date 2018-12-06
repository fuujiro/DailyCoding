/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: best.cpp
 * Contributor: fuujiro
 * Date: 12/06/2018
 * Description:
*
================================================================*/

#include <cmath>

class Solution {
public:
    vector<int> grayCode(int n) {
        int total = std::exp2(n);
        vector<int> out(total);

        out[0] = 0;

        int pow = 1;
        int len = 1;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<len; ++j)
            {
                out[len+j] = out[len-j-1] + pow;
            }
            pow *= 2;
            len *= 2;
        }
        return out;
    }

};
