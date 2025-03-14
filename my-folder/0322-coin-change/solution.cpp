class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int dp[13][10001];
        for(int i = 0 ; i < 13 ; i++)
        {
            for(int j = 0 ; j < 10001 ; j++)
            {
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = 0;
        for(int i = 1 ; i <= coins.size();i++)
        {
            for(int j = 0 ; j <= amount ; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
                if(j - coins[i - 1] >= 0)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        return dp[coins.size()][amount] != 1e9 ? dp[coins.size()][amount] : -1;
    }
};
