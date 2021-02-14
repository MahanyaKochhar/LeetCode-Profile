class Solution {
public:
        int dp[501][501];
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
            memset(dp,-1,sizeof(dp));
        int fin=minans(word1,word2,m,n);
        return fin;
    }
        int minans(string word1,string word2,int m1,int n1)
        {
                if(m1==0)
                        return n1;
                   if(n1==0)
                   return m1;
                if(dp[m1][n1]!=-1)
                                return dp[m1][n1];
                if(word1[m1-1]==word2[n1-1])
                        
                	return dp[m1][n1]=minans(word1,word2,m1-1,n1-1);
                else
                return dp[m1][n1]=1+min(minans(word1,word2,m1-1,n1),min(minans(word1,word2,m1,n1-1),minans(word1,word2,m1-1,n1-1)));
        }
};
