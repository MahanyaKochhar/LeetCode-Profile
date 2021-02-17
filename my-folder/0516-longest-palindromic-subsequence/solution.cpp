class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l=s.length();
        vector<vector<int>>dp(l+1,vector<int>(l+1,0));
        int i=1;
        int j=l;
        string s1=s;
        reverse(s.begin(),s.end());
        for(int i=1;i<l+1;i++)
            dp[i][i]=1;
        for(int i=1;i<l+1;i++)
        {
        	for(int j=1;j<l+1;j++)
        	{
        		 
        		  if(s1[i-1]==s[j-1])
        			dp[i][j]=1+dp[i-1][j-1];
        		else
        			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        	}
        }
        return dp[l][l];
    }
};
