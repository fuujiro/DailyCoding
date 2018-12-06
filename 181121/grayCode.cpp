/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: grayCode.cpp
 * Contributor: fuujiro
 * Date: 12/06/2018
 * Description:
*
================================================================*/

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> result;
		for (int i = 0;i < pow(2, n);++i)
			result.push_back(i ^ (i >> 1));
		return result;
	}
};

