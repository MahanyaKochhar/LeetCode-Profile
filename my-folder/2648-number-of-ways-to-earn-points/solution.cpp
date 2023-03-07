const int mod = 1e9 + 7;
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types)
    {
        int dp[51][1001];
        memset(dp, 0 , sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1 ; i <= types.size(); i++)
        {
            for(int j = 0 ; j <= 1000 ; j++)
            {
                for(int k = 0 ; k <= types[i-1][0] ; k++)
                {
                    if(j - k * types[i-1][1] >= 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j - k * types[i-1][1]]) % mod;
                }
            }
        }
        return dp[types.size()][target];
    }
};
