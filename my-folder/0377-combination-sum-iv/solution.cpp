class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<unsigned long long int>dp(target + 1);
        dp[0] = 1;
        for(int i = 1 ; i <= target; i++)
        {
            for(int j = 0 ; j < nums.size(); j++)
            {
                if(nums[j] <= i)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        // for(int i = 0 ; i < nums.size();i++)
        // {
        //     for(int j = 1 ; j <= target; j++)
        //     {
        //         if(j >= nums[i])
        //         {
        //             dp[j] += dp[j - nums[i]];
        //         }
        //     }
        // }
        return dp[target];
    }
};
