class Solution {
public:
    int numTrees(int n)
    {
        int dp[20];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        dp[0]=1;
        for(int j=2;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                dp[j]+=(dp[k-1]*dp[j-k]);
            }
        }
        return dp[n];
    }
};
