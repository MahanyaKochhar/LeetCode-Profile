class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        // int dp[amount+1][coins.size()+1];
        // memset(dp,INT_MAX,sizeof(dp));
        vector<vector< int>>dp(amount+1,vector<int>(coins.size()+1,INT_MAX-100));
        dp[0][0]=0;
        for(int j=0;j<=amount;j++)
        {
            for(int k=1;k<=coins.size();k++)
            {
                if(j>=coins[k-1])
                {
                    dp[j][k]=min(1+dp[j-coins[k-1]][k],dp[j][k-1]);
                }
                else
                    dp[j][k]=dp[j][k-1];
            }
            
        }
        if(dp[amount][coins.size()]!=INT_MAX-100)
            return dp[amount][coins.size()];
        else
            return -1;
     
    }
};
