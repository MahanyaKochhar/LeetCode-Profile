class Solution {
public:
    int minRemovals(vector<int>& nums, int target)
    {
        int maxi = 1e5;
        int dp[nums.size()][maxi];
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = 0 ; j < maxi ; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = 1;
        dp[0][nums[0]] = 0;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            for(int j = 0 ; j <= 1e4 ; j++)
            {
                dp[i][nums[i] ^ j] = min(dp[i][nums[i] ^ j],dp[i - 1][j]);
                if(dp[i - 1][j] != INT_MAX)
                {
                    dp[i][j] = min(dp[i][j],1 + dp[i - 1][j]);
                }
            }
        }
        return dp[nums.size() - 1][target] == INT_MAX ? -1 : dp[nums.size() - 1][target];
    }
};
