class Solution {
public:
    int minDistance(string word1, string word2) {
        // write your code here
        int len1=word1.size();
        int len2=word2.size();

        if(len1==0){
            return len2;
        }

        if(len2==0){
            return len1;
        }

        vector<vector<int> > dis(len1+1,vector<int>(len2+1));

        for(int i=0;i<=len1;i++){
            dis[i][0]=i;
        }

        for(int j=0;j<=len2;j++){
            dis[0][j]=j;
        }

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1]){
                    dis[i][j]=dis[i-1][j-1];
                }else{
                    dis[i][j]=min(min(dis[i-1][j],dis[i][j-1]),dis[i-1][j-1])+1;
                }
            }
        }

        return dis[len1][len2];
    }
};