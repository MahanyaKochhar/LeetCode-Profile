class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k)
    {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k + 1,-1)));
        dp[0][0][0] = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                for(int l = 0 ; l <= k ; l++)
                {
                    int cost = grid[i][j];
                    cost = (cost == 2) ? 1 : cost;
                    if(cost <= l)
                    {
                        if(i - 1 >= 0 && dp[i - 1][j][l - cost] != -1)
                        {
                            dp[i][j][l] = dp[i - 1][j][l - cost] + grid[i][j];
                        }
                        if(j - 1 >= 0 && dp[i][j - 1][l - cost] != -1)
                        {
                            dp[i][j][l] = max(dp[i][j][l],dp[i][j - 1][l - cost] + grid[i][j]);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(int l = 0; l <= k ; l++)
        {
            ans = max(ans,dp[grid.size() - 1][grid[0].size() - 1][l]);
        }
        return ans;
    }
};
