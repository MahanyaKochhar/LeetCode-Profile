class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid)
    {
        using ll = long long;
        const int mod = 1e9 + 7;
        ll dp[grid.size()][grid[0].size()][2];
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size(); j++)
            {
                dp[i][j][0] = -1e18;
                dp[i][j][1] = 1e18;
            }
        }
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(i - 1 >= 0 && j >= 0)
                {
                    if(grid[i][j] > 0)
                    {
                        dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j][0] * grid[i][j]);
                        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1] * grid[i][j]);
                    }
                    else
                    {
                        dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j][1] * grid[i][j]);
                        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] * grid[i][j]);
                    }
                }
                if(i >= 0 && j - 1 >= 0)
                {
                    if(grid[i][j] > 0)
                    {
                        dp[i][j][0] = max(dp[i][j][0],dp[i][j - 1][0] * grid[i][j]);
                        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] * grid[i][j]);
                    }
                    else
                    {
                        dp[i][j][0] = max(dp[i][j][0],dp[i][j - 1][1] * grid[i][j]);
                        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] * grid[i][j]);
                    }
                }
            }
        }
        if(dp[grid.size() - 1][grid[0].size() - 1][0] < 0)
        {
            return -1;
        }
        else
        {
            return dp[grid.size() - 1][grid[0].size() - 1][0] % mod;
        }
    }
};
