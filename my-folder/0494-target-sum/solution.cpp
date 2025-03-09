class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int dp[21][4001];
        memset(dp,false,sizeof(dp));
        int sum = 0;
        
        for(auto x : nums)
        {
            sum += x;
        }
        if(sum < abs(target))
        {
            return 0;
        }
        dp[0][sum] = 1;
        for(int i = 1 ; i <= nums.size();i++)
        {
            for(int j = 0 ; j <= 2 * sum; j++)
            {
                dp[i][j] += dp[i - 1][j + nums[i - 1]];
                if(j - nums[i - 1] >= 0)
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][target + sum];
    }
};
