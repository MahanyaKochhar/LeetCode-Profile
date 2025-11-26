class Solution {
public:
    int maxSumDivThree(vector<int>& nums)
    {
        vector<vector<int>>dp(nums.size() + 1,vector<int>(3,INT_MIN));
        dp[0][0] = 0;
        for(int i = 1 ; i <= nums.size(); i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                int k = (j + nums[i - 1]) % 3;
                dp[i][k] = max(dp[i - 1][k],dp[i - 1][j] + nums[i - 1]);
            }
        }
        return dp[nums.size()][0];
    }
};
