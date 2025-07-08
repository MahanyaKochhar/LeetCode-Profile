class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()));
        for(int i = 0 ; i < grid.size();i++)
        {
            for(int j = 0 ; j < grid[0].size(); j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                dp[i][j] = grid[i][j] + min(i - 1 >= 0 ? dp[i - 1][j] : INT_MAX,j - 1 >= 0 ? dp[i][j - 1] : INT_MAX);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
