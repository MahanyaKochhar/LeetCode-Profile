class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        double dp[301][5001];
        for(int i = 0 ; i < 301 ; i++)
        {
            for(int j = 0 ; j < 5001 ; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 1 ; i <= coins.size(); i++)
        {
            for(int j = 0 ; j <= amount ; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if((j - coins[i - 1]) >= 0)
                {
                    dp[i][j] = dp[i][j] +  dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};
