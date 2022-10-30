class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int dp[amount+1][coins.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j>=coins[i-1])
                    dp[j][i]=(dp[j-coins[i-1]][i]+dp[j][i-1]);
                else
                    dp[j][i]=(dp[j][i-1]);
            }
        }
        return dp[amount][coins.size()];
    }
};
