class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for(auto &x : nums)
        {
            sum += x;
        }
        int req = (sum + target) / 2;
        if(req < 0 || (sum + target) % 2  != 0)
        {
            return 0;
        }
        vector<vector<int>>dp(nums.size() + 1,vector<int>(2 * sum + 1,0));
        dp[0][0] = 1;
        for(int i = 1 ; i <= nums.size(); i++)
        {
            for(int j = 0 ; j <= req ; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j - nums[i - 1] >= 0)
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][req];

    }
};
