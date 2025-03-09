class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
       int sum = 0;
       for(auto x : nums)
       {
            sum += x;
       }
       if(sum % 2 != 0)
       {
            return false;
       }
       int v = sum / 2;
       bool dp[201][10001];
       memset(dp,false,sizeof(dp));
       dp[0][0] = true;
       for(int i = 1 ; i <= nums.size() ; i++)
       {
            for(int j = 1 ; j <= v ; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j - nums[i - 1] >= 0)
                {
                    dp[i][j] |= dp[i - 1][j - nums[i - 1]];
                }
            }
       }
       return dp[nums.size()][v];
    }
};
