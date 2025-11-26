const int mod = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        int dp[grid.size() + 1][grid[0].size() + 1][k];
        memset(dp, 0 ,sizeof(dp));
        dp[0][1][0] = 1;
        for(int i = 1 ; i <= grid.size() ; i++)
        {
            for(int j = 1 ; j <= grid[0].size() ; j++)
            {
                for(int l = 0 ; l < k ; l++)
                {
                    dp[i][j][(l + grid[i - 1][j - 1]) % k] = (dp[i - 1][j ][(l)] + dp[i][j - 1][l]) % mod;
                }
            }
        }
        return dp[grid.size()][grid[0].size()][0];
    }
};
