class Solution {
public:
    int integerBreak(int n)
    {
    	int dp[60];
    	memset(dp,0,sizeof(dp));
    	dp[0]=0;
    	dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        dp[4]=4;
        dp[5]=6;
        dp[6]=9;
    	for(int i=7;i<=n;i++)
    	{
    		for(int j=1;j<=i;j++)
    		{
    			dp[i]=max(dp[i-j]*j,dp[i]);
    		}
    	}
    	return dp[n];
        
    }
};
