class Solution {
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int dp[grid.size()][grid[0].size()];
        memset(dp, -1 , sizeof(dp));
        for(int j = 0 ; j < grid[0].size() ; j++)
        {
            for(int i = 0 ; i < grid.size() ; i++)
            {
                if(j == 0)
                    dp[i][j] = 0;
                else
                {
                    if(grid[i][j - 1] < grid[i][j] && dp[i][j - 1] != -1)
                        dp[i][j] = max(dp[i][j], 1 + dp[i][j - 1]);
                    if(i - 1 >= 0 && grid[i - 1][j - 1] < grid[i][j] && dp[i - 1][j - 1] != -1 )
                        dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                    if(i + 1 < grid.size() && grid[i + 1][j - 1] < grid[i][j] && dp[i + 1][j - 1] != -1)
                    dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - 1]);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
                ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};
