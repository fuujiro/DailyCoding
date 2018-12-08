/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: numDecoding.cpp
 * Contributor: fuujiro
 * Date: 12/08/2018
 * Description:
*
================================================================*/

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp[n];//dp[i] represent max ways util i
        memset(dp,0,sizeof(dp));
        dp[0]=(s[0]=='0')?0:1;
        if(!dp[0])return 0;
        for(int i=1;i<n;i++){
            if(s[i]>'0')
                dp[i]+=dp[i-1];
            if(s[i-1]!='0'&&(s[i-1]-'0')*10+s[i]-'0'<=26){
                if(i!=1)
                    dp[i]+=dp[i-2];
                else dp[i]+=1;
            }
        }
        return dp[n-1];
    }
};
