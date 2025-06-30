class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        vector<int>upd(nums.size() + 2,0);
        upd[0] = 1;
        for(int i = 1 ; i <= nums.size();i++)
        {
            upd[i] = nums[i - 1];
        }
        upd[nums.size() + 1] = 1;
        vector<vector<int>>dp(nums.size() + 2,vector<int>(nums.size() + 2,0));
        for(int len = 3; len <= upd.size(); len++)
        {
            for(int i = 0 ; i <= upd.size() - len; i++)
            {
                int j = i + len - 1;
                for(int k = i + 1; k < j ; k++)
                {
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + upd[i] * upd[k] * upd[j]);
                }
            }
        }
        return dp[0][nums.size() + 1];
    }
};
